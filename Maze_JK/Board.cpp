#include "Board.h"

using namespace std;

Board::Board()
{
	cout << "\nKonstruktro Board\n\n";
	field_init();
}


Board::~Board()
{
}

void Board::info()
{
	cout << "Plansza ma " << field.size() << " elementow \n";
	cout << "Wymiary planszy to " << width + frame_sized
		<< " x " << length + frame_sized << "\n";

	cout.width(2);
	int licznik = 1;
	for (auto i : field)
	{
		cout.width(4);
		//cout << i.check_if_visited();
		i.p_id();
		if (!(licznik % (width + 2)))
		{
			cout << endl;
		}
		licznik++;
	}
	cout << endl;
}

int Board::get_width()
{
	return width;
}

int Board::get_length()
{
	return length;
}

Patch & Board::operator[](std::size_t idx)
{
	return field[idx];
}

void Board::field_init()
{
	int max_dimension = sqrt(numeric_limits<int>::max()) - 2;
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
	std::vector<Patch> tmp((width + frame_sized) * (length + frame_sized));
	field = move(tmp);
	frame_init();
}

void Board::frame_init()
{
	const int v_distance = (width + 2) * (length + 1);
	const int h_distance = width + 1;

	for (int i = 0; i <= width + 1; ++i)
	{
		field[i].make_visited(0);
		field[i + v_distance].make_visited(0);
	}

	for (int i = 1; i <= length + 1; ++i)
	{
		field[i*(width + 2)].make_visited(0);
		field[i*(width + 2) + h_distance].make_visited(0);
	}
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

