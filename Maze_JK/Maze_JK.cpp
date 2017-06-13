// Maze_JK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Maze.h"
#include "M_solver.h"

using namespace std;

int main()
{
	cout << "witaj\n";

	//Maze jeden{};
	//jeden.info();
	//jeden.generate_maze();
	//jeden.info();

	//jeden.to_pgm_file();
	M_solver testy{};
	testy.load_f();

    return 0;
}

