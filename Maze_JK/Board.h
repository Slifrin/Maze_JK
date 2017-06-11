#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <math.h>
#include <utility>
#include <random>
#include "Patch.h"

class Board
{
public:
	Board();
	~Board();
	void info();
	int get_width();
	int get_length();

private:
	//TODO dodac sprawdzanie rozmiaru
	void field_init();
	void frame_init();

	bool evaluate_length(int max_dimension);

	bool evaluate_width(int max_dimension);


	int width{ -1 };
	int length{ -1 };
	int frame_sized{ 2 };
	std::vector<Patch> field;
};

