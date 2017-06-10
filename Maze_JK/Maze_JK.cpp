// Maze_JK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Maze.h"

using namespace std;

int main()
{
	cout << "witaj\n";
	
	Maze jeden{};
	jeden.info();

	/*for (int i = 0; i < 100; ++i)
	{	
		cout << i << " : ";

	random_device rseed;
	mt19937_64 rgen(rseed());
	uniform_int_distribution<int> idist2(0, 1);
	bool test = idist2(rgen);
	cout << test << endl;
	}*/

    return 0;
}

