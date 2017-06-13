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
	void solve();
private:
	
	std::string get_f_name();
	void get_w_and_l(std::string buf);
	void get_white(std::string buf);
	
	std::vector<Direction> possible_moves(Patch  current);
	Direction draw_direction(std::vector<Direction> possible_moves);

	Patch preaper_patch(int current_id);
	int go_next(Direction nex_dir);
	void pri_sta(std::stack<Patch> trasa);

	int white{ -1 };
	int width{ -1 };
	int length{ -1 };
	std::pair <int, int> start_end{ -1, -1 };
	std::string header{};
	std::vector<int> field;
	std::string f_name{};
};

