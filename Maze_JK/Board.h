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

private:
	void field_init();

	bool evaluate_length(int max_dimension);

	bool evaluate_width(int max_dimension);

	int width{ -1 };
	int length{ -1 };
	std::vector<Patch> field;
};

