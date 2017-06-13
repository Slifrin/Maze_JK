#include "M_solver.h"

using namespace std;

M_solver::M_solver()
{
}


M_solver::~M_solver()
{
}

void M_solver::load_f()
{	
	unique_ptr<ifstream> myfile_p( new ifstream);
	string name{ get_f_name() };	
	myfile_p->open(name);
	if (myfile_p->good())
	{
		string bufor{};
		getline(*myfile_p, bufor);
		while ((bufor[0] == 'P' )||(bufor[0] == '#'))
		{	
			header += bufor;
			bufor.clear();			
			getline(*myfile_p, bufor);						
		}
		header += bufor;
		get_w_and_l(bufor);
		bufor.clear();
		getline(*myfile_p, bufor);
		get_white(bufor);
		header += bufor;
		bufor.clear();

		*myfile_p >> bufor;
		//field.resize(lenght * width);
		while (!myfile_p->eof())
		{			
			field.push_back(stoi(bufor));
			if (start_end.first == -1 || start_end.second == -1)
			{
				if (field.back() == white - 1)
				{
					start_end.first = field.size() - 1;
				}
				else if (field.back() == 1)
				{
					start_end.second = field.size() - 1;
				}
			}	
			*myfile_p >> bufor;
		}
		cout << "Poczatek: " << start_end.first << " Koniec: " << start_end.second << endl;
	}
	else
	{
		//TODO throw exeption informing file is not good (check docs)
	}
	cout << width*length << " vs " << field.size() << endl;
}

void M_solver::info()
{
	for (int i = 0; i < length; i++)
	{
		cout << endl;
		for (int j = 0; j < width; j++)
		{
			cout << field[j + (length*i)] << " ";
		}
	}
	cout << endl;
}

std::string M_solver::get_f_name()
{
	string name{};
	cin.clear();
	while (name == "")
	{
		cout << "Prosze podac nazwe pliku jaki ma byc wczytany\n";
		getline(cin, name);
		name.erase(remove_if(name.begin(),
			name.end(),
			[](char c)
		{ return c == ',' || c == '.' || c == '<' || c == '>' || c == '"'; }),
			name.end());
	}
	name += ".pgm";
	cout << "Wczytany zostanie plik o nazwie " << name << endl;
	return name;
}

void M_solver::get_w_and_l(std::string buf)
{
	string result{};
	regex r("[[:digit:]]+");
	smatch match;
	if (regex_search(buf, match, r) )
	{
		if (match.size() == 1)
		{
			result = match.str(0);			
			width = stoi(result);
			length = stoi(result);
		}
		else if (true)
		{
			result = match.str(0);
			width = stoi(result);			
			result = match.str(1);
			length = stoi(result);
		}			
	}
	else 
	{
		cout << "TARAPATY\n";
	}
	cout << "W: " << width << " L: " << length << endl;

}

void M_solver::get_white(std::string buf)
{
	white = stoi(buf);
	cout << "Bialy: " << white << endl;
}

void M_solver::solve()
{
	stack<Patch> trasa{};
	Patch current{};
	current.make_visited(start_end.first);
	trasa.push(current);



	trasa.top().r_id();


}

Patch M_solver::visit(int next)
{
	return Patch();
}

std::vector<Direction> M_solver::possible_moves(int current_id)
{
	vector <Direction> directions{};
	int top = current_id - width;
	int bottom = current_id + width;
	int left = current_id - 1;
	int right = current_id + 1;

	if (field[top])
	{
		directions.push_back(Direction::top);
	}
	if (field[bottom])
	{
		directions.push_back(Direction::bottom);
	}
	if (field[left])
	{
		directions.push_back(Direction::left);
	}
	if (field[right])
	{
		directions.push_back(Direction::right);
	}
	return directions;
}

Direction M_solver::draw_direction(std::vector<Direction> possible_moves)
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

bool M_solver::is_move_posi(int id)
{
	bool decision{ false };
	if (field[id])
	{
		decision = true;
	}
	else
	{
		decision = false;
	}
	return decision;
}

void M_solver::narrow_p(Patch current)
{
	//TODO zmienic na odwrotnosc !!!!!!!!
	vector<Direction> moves = impossible_moves(current.r_id);
	for (int i = 0; i < moves.size(); i++)
	{
		current.add_wall(moves[i]);
	}



}

std::vector<Direction> M_solver::impossible_moves(int current_id)
{
	vector <Direction> directions{};
	int top = current_id - width;
	int bottom = current_id + width;
	int left = current_id - 1;
	int right = current_id + 1;

	if (!field[top])
	{
		directions.push_back(Direction::top);
	}
	if (!field[bottom])
	{
		directions.push_back(Direction::bottom);
	}
	if (!field[left])
	{
		directions.push_back(Direction::left);
	}
	if (!field[right])
	{
		directions.push_back(Direction::right);
	}
	return directions
}
