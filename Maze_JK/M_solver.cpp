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
