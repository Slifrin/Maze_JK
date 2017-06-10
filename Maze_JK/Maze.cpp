#include "Maze.h"

using namespace std;

Maze::Maze()
{
	field_init();
}

Maze::~Maze()
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
}


bool Maze::evaluate_length(int max_dimension)
{	
	if (length <= 0)
	{
		cout << "Dlugosc labiryntu nie moze byc mniejsza od 1";
		return false;
	}
	else if(max_dimension < length)
	{
		cout << "Labirynt jest za dlugi aby go wygenerowac";
		return false;
	}
	else
	{
		return true;
	}
	
}

bool Maze::evaluate_width(int max_dimension)
{
	if (width <= 0)
	{
		cout << "Szerokosc labiryntu nie moze byc mniejsza od 1";
		return false;
	}
	else if (max_dimension < width)
	{
		cout << "Labirynt jest za szeroki aby go wygenerowac";
		return false;
	}
	else
	{
		return true;
	}	
}
