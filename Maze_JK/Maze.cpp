#include "Maze.h"

using namespace std;

const int white = 9;
const int black = 0;


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

void Maze::to_pgm_file()
{
	unique_ptr<ofstream> myfile_p(new ofstream);
	string name{ get_f_name() };
	myfile_p->open(name);
	const int retreat{ (2 * width + 1) * 2 + 1};
	if (myfile_p->is_open())
	{
		//TODO exeption with vriting to file
		string headline{ create_f_headline() };
		*myfile_p << headline;

		for (int  m_line = 1; m_line <= length; m_line++)
		{
			const int max = (m_line + 1) * (width + 2) - 1;
			for (int f_w_current = (m_line * (width + 2)) + 1; f_w_current < max; f_w_current++)
			{
				for (int col = 0; col < 3; col++)
				{
					*myfile_p << to_string(put_mark_top(f_w_current, col)) << " ";
				}				
				if ((f_w_current + 1) != max) myfile_p->seekp(long(myfile_p->tellp()) - 2);
			}
			myfile_p->seekp(long(myfile_p->tellp()) - 1);
			*myfile_p << "\n";

			for (int f_w_current = (m_line * (width + 2)) + 1; f_w_current < max; f_w_current++)
			{
				for (int col = 0; col < 3; col++)
				{
					*myfile_p << to_string(put_mark_mid(f_w_current, col)) << " ";
				}
				if ((f_w_current + 1) != max) myfile_p->seekp(long(myfile_p->tellp()) - 2);
			}
			myfile_p->seekp(long(myfile_p->tellp()) - 1);
			*myfile_p << "\n";

			for (int f_w_current = (m_line * (width + 2)) + 1; f_w_current < max; f_w_current++)
			{
				for (int col = 0; col < 3; col++)
				{
					*myfile_p << to_string(put_mark_bot(f_w_current, col)) << " ";
				}
				if ((f_w_current + 1) != max) myfile_p->seekp(long(myfile_p->tellp()) - 2);
			}
			myfile_p->seekp(long(myfile_p->tellp()) - 1);
			*myfile_p << "\n";
			myfile_p->seekp(long(myfile_p->tellp()) - retreat);
		}
	}
	else
	{
		//TODO throw exeption informing file is not open (check docs)
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

std::string Maze::get_f_name()
{
	string name{};	
	cin.clear();
	getline(cin, name);
	//TODO naprawic wyswietlanie
	while (name=="")
	{
		cout << "Prosze podac nazwe pliku pod jaka ma byc zapisany\n";
		getline(cin, name);
		name.erase(remove_if(name.begin(),
			name.end(),
			[](char c)
		{ return c == ',' || c == '.' || c == '<' || c == '>' || c == '"'; }),
			name.end());
	}
	name += ".pgm";
	cout << "zapisany zostanieplik o nazwie " << name << endl;
	return name;
}

std::string Maze::create_f_headline()
{
	string headline{};
	headline += "P2\n";
	headline += "# ";
	headline += "W pliku znajduje sie labirynt z jednym rozwi¹zaniem\n";
	headline += "# Labirynt ma pocz¹tek w punkcie ";
	headline += to_string(start_end.first);
	headline += " a koniec w punkcie ";
	headline += to_string(start_end.second);
	headline += "\n";
	headline += to_string(2 * width + 1);
	headline += " ";
	headline += to_string(2 * length + 1);
	headline += "\n";
	headline += to_string(white);
	headline += "\n";

	return headline;
}

int Maze::put_mark_top(int f_w_current,const int cloumn)
{
	int color{ white };
	switch (cloumn)
	{
	case 0:
		if (area[f_w_current].is_wall_ther(Direction::top) ||
			area[f_w_current].is_wall_ther(Direction::left))
		{
			color = black;
		}
		else
		{
			if (area[f_w_current - 1].is_wall_ther(Direction::top) ||
				area[f_w_current - width - 2].is_wall_ther(Direction::left))
			{
				color = black;
			}
		}
		break;
	case 1:
		if (area[f_w_current].is_wall_ther(Direction::top))
		{
			color = black;
		}
		break;
	case 2:
		if (area[f_w_current].is_wall_ther(Direction::top) ||
			area[f_w_current].is_wall_ther(Direction::right))
		{
			color = black;
		}
		break;
	default:
		break;
	}
	return color;
}

int Maze::put_mark_mid(int f_w_current, const int cloumn)
{
	int color{ white };
	switch (cloumn)
	{
	case 0:
		if (area[f_w_current].is_wall_ther(Direction::left))
		{
			color = black;
		}
		break;
	case 2:
		if (area[f_w_current].is_wall_ther(Direction::right))
		{
			color = black;
		}
		break;
	default:
		break;
	}
	return color;
}

int Maze::put_mark_bot(int f_w_current, const int cloumn)
{
	int color{ white };
	switch (cloumn)
	{
	case 0:
		if (area[f_w_current].is_wall_ther(Direction::left) ||
			area[f_w_current].is_wall_ther(Direction::bottom) )
			
		{
			color = black;
		}
		break;
	case 1:
		if (area[f_w_current].is_wall_ther(Direction::bottom))
		{
			color = black;
		}
		break;
	case 2:
		if (area[f_w_current].is_wall_ther(Direction::right) ||
			area[f_w_current].is_wall_ther(Direction::bottom))			
		{
			color = black;
		}
		break;
	default:
		break;
	}
	return color;
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
