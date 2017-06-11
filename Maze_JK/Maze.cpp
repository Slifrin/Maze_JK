#include "Maze.h"

using namespace std;

Maze::Maze()
{
	width = area.get_width();
	length = area.get_length();
	find_start_end();
}

Maze::~Maze()
{
}

void Maze::info()
{	
	area.info();	
	cout << "Poczatek " << start_end.first << " Koniec " << start_end.second << "\n\n";
	/*cout << "labirynt ma " << area.size() << " elementow \n";
	cout << "WYmiary labiryntu to " << width << " x " << length << "\n";
	pair <int, int> test = find_start_end();
	cout << "Poczatek " << test.first << " Koniec " << test.second << "\n";

	int licznik = 1;
	for (auto i: area)
	{
		cout << i.check_if_visited();
		if (!(licznik % width))
		{
			cout << endl;
		}
		licznik++;
	}
	cout << endl;*/
}

void Maze::generate_maze()
{
	int current{ start_end.first };
	int previous{ -1 };
	int counter{ 1 };
	stack<int> order{};
	order.push(current);
	Direction next_d{ Direction::none };

	while (!order.empty())
	{		
		if (!area[current].check_if_visited())
		{
			area[current].make_visited(counter);
		}		
		next_d = draw_direction(possible_moves(current));
		if (next_d != Direction::none)
		{		
			area[current].remove_wall(next_d);
			current = move_to(current, next_d);

			next_d = reverse_dir(next_d);
			area[current].remove_wall(next_d);
			order.push(current);
			next_d = Direction::none;
			counter++;
		}
		else
		{			
			current = order.top();
			order.pop();								
		}		
	}
}

bool Maze::draw_bool()
{
	random_device rseed;
	mt19937_64 rgen(rseed());
	uniform_int_distribution<int> idist(0, 1);

	return idist(rgen);
}

std::vector<Direction> Maze::possible_moves(int current_id)
{
	vector <Direction> directions{};
	int top = current_id - width - 2;
	int bottom = current_id + width + 2;
	int left = current_id - 1;
	int right = current_id + 1;

	if (!area[top].check_if_visited())
	{
		directions.push_back(Direction::top);
	}
	if (!area[bottom].check_if_visited())
	{
		directions.push_back(Direction::bottom);
	}
	if (!area[left].check_if_visited())
	{
		directions.push_back(Direction::left);
	}
	if (!area[right].check_if_visited())
	{
		directions.push_back(Direction::right);
	}
	return directions;
}

Direction Maze::draw_direction(std::vector<Direction> possible_moves)
{
	int rozmiar{ -1 };
	rozmiar = possible_moves.size();
	if (rozmiar == 0)
	{
		return Direction::none;
	}
	else if (rozmiar == 1)
	{
		return possible_moves[0];
	}
	else
	{
		random_device rseed;
		mt19937_64 rgen(rseed());
		uniform_int_distribution<int> idist(0, rozmiar - 1);

		return possible_moves[idist(rgen)];
	}
}

int Maze::move_to(int current, Direction dir)
{
	int n_position{ -1 };
	switch (dir)
	{
	case Direction::top:
		n_position = current - width - 2;
		break;
	case Direction::bottom:
		n_position = current + width + 2;
		break;
	case Direction::left:
		n_position = current - 1;
		break;
	case Direction::right:
		n_position = current + 1;
		break;
	default:
		break;
	}
	return n_position;
}

int Maze::draw_star_or_end()
{
	int position{ -1 };
	random_device rseed;
	mt19937_64 rgen(rseed());

	bool top_righ = draw_bool();
	bool left_bottom = draw_bool();

	if (top_righ) {
		uniform_int_distribution<int> idist(1, width);
		if (left_bottom) {										//top
			position = idist(rgen) + width + 2;
		}
		else {													//bottom
			position = idist(rgen) + (length) * (width + 2);
		}
	}
	else {
		uniform_int_distribution<int> idist(1, length);
		if (left_bottom) {										//left
			position = idist(rgen)*(width + 2) + 1;
		}
		else {													//right
			position = (idist(rgen) + 1) * (width + 2) - 2;
		}
	}
	return position;
}

void Maze::find_start_end()
{
	int start{ -1 };
	int end{ -1 };

	while (start == end){
		start = draw_star_or_end();
		end = draw_star_or_end();
	}

	start_end.first = start;
	start_end.second = end;
}
