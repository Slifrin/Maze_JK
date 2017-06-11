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
