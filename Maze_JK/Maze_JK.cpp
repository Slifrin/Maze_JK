// Maze_JK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Maze.h"
#include "M_solver.h"

using namespace std;

int main()
{
	cout << "Witaj\n";

	Maze jeden{};
	jeden.generate_maze();
	jeden.info();
	jeden.to_pgm_file();

	cout << "\n\n ROZWIAZYWANIE \n\n";
	M_solver testy{};
	testy.load_f();
	testy.solve();
	testy.s_solution_to_f();

    return 0;
}

