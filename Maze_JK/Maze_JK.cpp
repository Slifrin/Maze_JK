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

	int c{10};	
	c = sqrt( numeric_limits<int>::max());
	cout << c << endl;
	int d = 4;
	int e{ 5 };

	std::vector<int> tmp(d * e);
	for (auto i : tmp) cout << i<<"\n";
	cout << "#################\n";
	std::vector<int> tmp2;
	tmp2 = move(tmp);
	for (auto i : tmp2) cout << i << "\n";

    return 0;
}

