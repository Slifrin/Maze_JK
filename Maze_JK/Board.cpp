#include "Board.h"

using namespace std;

Board::Board()
{
	field_init();
}


Board::~Board()
{
}

void Board::info()
{
	cout << "Plansza ma " << field.size() << " elementow \n";
	cout << "WYmiary planszy to " << width << " x " << length << "\n";

	int licznik = 1;
	for (auto i : field)
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

void Board::field_init()
{
	int max_dimension = sqrt(numeric_limits<int>::max());
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

bool Board::evaluate_length(int max_dimension)
{
	if (length <= 0) {
		cout << "Dlugosc labiryntu nie moze byc mniejsza od 1\n";
		return false;
	}
	else if (max_dimension < length) {
		cout << "Labirynt jest za dlugi aby go wygenerowac\n";
		return false;
	}
	else {
		return true;
	}
}

bool Board::evaluate_width(int max_dimension)
{
	if (width <= 0) {
		cout << "Szerokosc labiryntu nie moze byc mniejsza od 1\n";
		return false;
	}
	else if (max_dimension < width) {
		cout << "Labirynt jest za szeroki aby go wygenerowac\n";
		return false;
	}
	else {
		return true;
	}
}

