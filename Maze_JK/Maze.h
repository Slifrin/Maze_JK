#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <math.h>
#include <utility>
#include <random>
#include "Board.h"
#include "Patch.h"

enum class Direction : int
{
	top = 0,
	bottom = 1,
	left = 2,
	right = 3,
	none = 4
};


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
	bool draw_bool();

	int check_moves(Patch current_id, Direction turn);
	std::vector<Direction> possible_moves(int current);
	Direction draw_direction(std::vector<Direction> possible_moves);


	//TODO zmienic nazwe draw_start_or_end
	int draw_star_or_end();
	// TODO void patch_position();
	std::pair<int, int> find_start_end();
	int width{ -1 };
	int length{ -1 };
	std::pair <int, int> start_end{ -1, -1 };

	Board area;	
};

