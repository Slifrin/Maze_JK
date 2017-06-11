#include "Maze.h"

using namespace std;

Maze::Maze()
{
	width = area.get_width();
	length = area.get_length();
}

Maze::~Maze()
{
}

void Maze::info()
{	
	area.info();
	pair <int, int> test = find_start_end();
	cout << "Poczatek " << test.first << " Koniec " << test.second << "\n";
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
	int current = start_end.first;
	Patch current = area[start_end.first];
	int counter{ 1 };

	Direction possible = draw_direction(possible_moves(current));

	
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
		uniform_int_distribution<int> idist(0, rozmiar);

		return possible_moves[idist(rgen) - 1];
	}
}

int Maze::check_moves(Patch current, Direction turn)
{
	
	return 0;
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

std::pair<int, int> Maze::find_start_end()
{
	int start{ -1 };
	int end{ -1 };

	while (start == end){
		start = draw_star_or_end();
		end = draw_star_or_end();
	}

	start_end.first = start;
	start_end.second = end;
	return { start, end };
}
