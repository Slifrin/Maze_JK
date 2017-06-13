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

enum class row : int
{
	top = 1,
	middle = 2,
	bottom = 3
};

class Maze
{
public:
	Maze();
	~Maze();
	
	void info();
	void generate_maze();
	void to_pgm_file();
private:
	bool draw_bool();
	std::vector<Direction> possible_moves(int current);
	Direction draw_direction(std::vector<Direction> possible_moves);
	int move_to(int current, Direction dir);
	std::string get_f_name();

	std::string create_f_headline();
	int put_mark_top(int f_w_current,const int cloumn);
	int put_mark_mid(int f_w_current, const int cloumn);
	int put_mark_bot(int f_w_current, const int cloumn);

	//TODO zmienic nazwe draw_start_or_end
	int draw_star_or_end();
	void find_start_end();
	int width{ -1 };
	int length{ -1 };
	std::pair <int, int> start_end{ -1, -1 };

	Board area{};
};

