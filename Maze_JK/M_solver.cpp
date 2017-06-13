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
		get_start_end(bufor);
		bufor.clear();
		getline(*myfile_p, bufor);
		get_white(bufor);
		header += bufor;
		bufor.clear();

		field.resize(lenght * width);
		while (myfile_p->eof())
		{
			*myfile_p >> bufor;
			field.push_back(stoi(bufor));
		}
	}
	else
	{
		//TODO throw exeption informing file is not good (check docs)
	}
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
	cout << "Wczytany zostanieplik o nazwie " << name << endl;
	return name;
}

void M_solver::get_start_end(std::string buf)
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
			lenght = stoi(result);
		}
		else if (true)
		{
			result = match.str(0);
			width = stoi(result);			
			result = match.str(1);
			lenght = stoi(result);			
		}			
	}
	else 
	{
		cout << "TARAPATY\n";
	}
	cout << "W: " << width << " L: " << lenght << endl;

}

void M_solver::get_white(std::string buf)
{
	white = stoi(buf);
	cout << "Bialy: " << white << endl;
}
