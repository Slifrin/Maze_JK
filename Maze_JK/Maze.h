#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <math.h>
#include <utility>
#include <random>
#include <fstream>
#include <algorithm>
#include <memory>
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
	void to_pgm_file();
private:
	bool draw_bool();
	std::vector<Direction> possible_moves(int current);
	Direction draw_direction(std::vector<Direction> possible_moves);
	int move_to(int current, Direction dir);
	std::string get_f_name();


	void save_to_f(std::unique_ptr<std::ofstream> myfile_p,
		std::string f_name);
	std::string create_f_headline();

	//TODO zmienic nazwe draw_start_or_end
	int draw_star_or_end();
	// TODO void patch_position();
	void find_start_end();
	int width{ -1 };
	int length{ -1 };
	std::pair <int, int> start_end{ -1, -1 };

	Board area{};
};

