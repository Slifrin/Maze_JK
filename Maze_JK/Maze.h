#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <utility>
#include "Patch.h"

class Maze
{
public:
	Maze();
	~Maze();

private:
	//TODO dodac sprawdzanie rozmiaru
	void field_init();

	bool evaluate_length(int max_dimension);

	bool evaluate_width(int max_dimension);

	int width{ -1 };
	int length{ -1 };
	int frame_sized{ 2 };
	std::vector<Patch> field;
};

