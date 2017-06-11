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
	std::vector<Direction> possible_moves(int current);
	Direction draw_direction(std::vector<Direction> possible_moves);
	int move_to(int current, Direction dir);

	//TODO zmienic nazwe draw_start_or_end
	int draw_star_or_end();
	// TODO void patch_position();
	void find_start_end();
	int width{ -1 };
	int length{ -1 };
	std::pair <int, int> start_end{ -1, -1 };

	Board area{};
};

