#pragma once
#include <cstddef>
#include <iostream>
#include <vector>
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
		
	Patch& operator[](std::size_t idx);

private:
	//TODO dodac sprawdzanie rozmiaru
	//TODO zmienic minimalny rozmiar labiryntu na 2
	void field_init();
	void frame_init();
	bool evaluate_length(int max_dimension);
	bool evaluate_width(int max_dimension);

	int width{ -1 };
	int length{ -1 };
	int frame_sized{ 2 };
	int min_dim{ 2 };
	std::vector<Patch> field;
};

