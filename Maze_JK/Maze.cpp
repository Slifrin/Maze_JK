#include "Maze.h"

using namespace std;

Maze::Maze()
{
	field_init();
}

Maze::~Maze()
{
}

void Maze::info()
{	
	cout << "labirynt ma " << field.size() << " elementow \n";
	cout << "WYmiary labiryntu to " << width << " x " << length << "\n";
	pair <int, int> test = find_start_end();
	cout << "Poczatek " << test.first << " Koniec " << test.second << "\n";

	int licznik = 1;
	for (auto i: field)
	{
		cout << i.check_if_visited();
		if (!(licznik % width))
		{
			cout << endl;
		}
		licznik++;
	}
	cout << endl;
}

void Maze::generate_maze()
{
	

}

void Maze::field_init()
{
	int max_dimension = sqrt(numeric_limits<int>::max()) - frame_sized;
	cout << "Prosze podac rozmiar labiryntu \n";
	
	while (!evaluate_width(max_dimension))
	{
		cout << "Podaj szerokosc labiryntu \n";
		cin >> width;
	}
	while (!evaluate_length(max_dimension))
	{
		cout << "Podaj dlugosc labiryntu \n";
		cin >> length;
	}
	std::vector<Patch> tmp(width * length);
	field = move(tmp);
	//frame_init();
}

bool Maze::evaluate_length(int max_dimension)
{	
	if (length <= 0){
		cout << "Dlugosc labiryntu nie moze byc mniejsza od 1\n";
		return false;
	}
	else if(max_dimension < length){
		cout << "Labirynt jest za dlugi aby go wygenerowac\n";
		return false;
	}
	else{
		return true;
	}	
}

bool Maze::evaluate_width(int max_dimension)
{
	if (width <= 0){
		cout << "Szerokosc labiryntu nie moze byc mniejsza od 1\n";
		return false;
	}
	else if (max_dimension < width){
		cout << "Labirynt jest za szeroki aby go wygenerowac\n";
		return false;
	}
	else {
		return true;
	}	
}

void Maze::frame_init()
{
	const int v_distance = (width + 2) * (length + 1);
	const int h_distance = width + 1;

	for (int  i = 0; i <= width + 1; ++i)
	{		
		field[i].make_visited();
		field[i + v_distance].make_visited();
	}

	for (int i = 1; i <= length + 1; ++i)
	{
		field[i*(width + 2)].make_visited();
		field[i*(width + 2) + h_distance].make_visited();
	}
}

bool Maze::draw_bool()
{
	random_device rseed;
	mt19937_64 rgen(rseed());
	uniform_int_distribution<int> idist(0, 1);

	return idist(rgen);
}

int Maze::draw_star_or_end()
{
	int position{ -1 };
	random_device rseed;
	mt19937_64 rgen(rseed());

	bool top_righ = draw_bool();
	bool left_bottom = draw_bool();

	if (top_righ){
		uniform_int_distribution<int> idist(1, width);
		if (left_bottom){										//top
			position = idist(rgen);
		}
		else{													//bottom
			position =  (length) * (width) - idist(rgen);
		}
	}
	else{
		uniform_int_distribution<int> idist(1, length);
		if (left_bottom){										//left
			position = idist(rgen)*(width);
		}
		else{													//right
			position = idist(rgen)*(width + 1) -1;
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
