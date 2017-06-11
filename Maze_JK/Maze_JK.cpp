// Maze_JK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Maze.h"

using namespace std;

enum class Direction1 : int
{
	top = 1,
	bottom = 2,
	left = 3,
	right = 4
};


int main()
{
	cout << "witaj\n";
	Patch a{  };
	a.spr_wsk();

	Maze jeden{};
	jeden.info();
	jeden.generate_maze();

	Direction1 b{};
	cout << int(b) << endl;
	b = Direction1::top;
	cout << int(b) << endl;

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

