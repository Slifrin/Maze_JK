#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <regex>


class M_solver
{
public:
	M_solver();
	~M_solver();

	void load_f();
private:
	
	std::string get_f_name();
	void get_start_end(std::string buf);
	void get_white(std::string buf);

	int white{ -1 };
	int width{ -1 };
	int lenght{ -1 };
	std::pair <int, int> start_end{ -1, -1 };
	std::string header{};
	std::vector<int> field;
};

