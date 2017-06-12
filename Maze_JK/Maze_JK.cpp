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
	jeden.info();

	jeden.to_pgm_file();

	/*int d{ 10 };
	stack<int> spr{};
	spr.push(d);

	for (int i = 1; i <= 10; i++)
	{
		d += i;
		spr.push(d);
	}
	while (!spr.empty())
	{
		cout << spr.top() << endl;
		spr.pop();
	}*/
	
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

