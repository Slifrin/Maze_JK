// Maze_JK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Maze.h"

using namespace std;

int main()
{
	cout << "witaj\n";
	Patch a;
	Patch b;

	a.spr_wsk();
	b.spr_wsk();

	int c{ 10 };
	c = sqrt(numeric_limits<int>::max());
	cout << c << endl;
	int d = 4;
	int e{ 5 };

	//std::vector<int> tmp(d * e);
	//for (auto i : tmp) cout << i<<"\n";
	//cout << "#################\n";
	//std::vector<int> tmp2;
	//tmp2 = move(tmp);
	//for (auto i : tmp2) cout << i << "\n";

	Maze jeden{};
	jeden.info();

	//int f{};
	//cin >> f;
	//for (int i = 0; i < 100; ++i)
	//{	
	//	cout << i << " : ";
	//random_device rseed;
	//mt19937_64 rgen(rseed());
	//uniform_int_distribution<int> idist(0, f);

	//cout << idist(rgen) << endl;

	//uniform_int_distribution<int> idist2(0, 1);
	//bool test = idist2(rgen);
	//cout << test << endl;
	//}

    return 0;
}

