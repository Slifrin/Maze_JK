#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <regex>
#include <random>
#include <stack>

#include "Patch.h"


class M_solver
{
public:
	M_solver();
	~M_solver();

	void load_f();
	void info();
private:
	
	std::string get_f_name();
	void get_w_and_l(std::string buf);
	void get_white(std::string buf);
	void solve();
	Patch visit(int next);
	std::vector<Direction> possible_moves(int current_id);
	Direction draw_direction(std::vector<Direction> possible_moves);
	bool is_move_posi(int id);
	void narrow_p(Patch current);
	std::vector<Direction> impossible_moves(int current_id);

	int white{ -1 };
	int width{ -1 };
	int length{ -1 };
	std::pair <int, int> start_end{ -1, -1 };
	std::string header{};
	std::vector<int> field;
};

