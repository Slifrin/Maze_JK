#pragma once
#include <iostream>
#include <array>

struct wall
{
public:
	void disappear();
	bool is_w_ther();
private:
	bool exist{ true };
};

class Patch
{
public:
	Patch();
	~Patch();

	//TODO do zmiany 
	void spr_wsk();
	//TODO enum direction 
	void remove_wall();
	void make_visited(int id);
	bool check_if_visited();
private:
	bool is_visited{ false };
	int id{ -1 };
	Patch * previous{};
	std::array<wall, 4>P_walls{};
};



