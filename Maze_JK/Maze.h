#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <math.h>
#include <utility>
#include <random>
#include "Patch.h"

class Maze
{
public:
	Maze();
	~Maze();

	//TODO zmienic wyswietlane informacje
	void info();
	//TODO generowanie labiryntu
	void generate_maze();

private:
	//TODO dodac sprawdzanie rozmiaru
	void field_init();

	bool evaluate_length(int max_dimension);

	bool evaluate_width(int max_dimension);
	
	void frame_init();

	bool draw_bool();

	int draw_star_or_end();
	// TODO void patch_position();
	std::pair<int, int> find_start_end();

	int width{ -1 };
	int length{ -1 };
	int frame_sized{ 2 };
	std::pair <int, int> start_end{ -1, -1 };
	std::vector<Patch> field;
};

