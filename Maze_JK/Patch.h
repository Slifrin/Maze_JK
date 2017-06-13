#pragma once
#include <iostream>
#include <array>

enum class Direction : int
{
	top = 0,
	bottom = 1,
	left = 2,
	right = 3,
	none = 4
};

struct wall
{
public:
	void disappear();
	void appear();
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
	void remove_wall(Direction to_remove);
	void make_visited(int n_id);
	bool check_if_visited();
	void p_id();
	bool is_wall_ther(Direction current_dir);
	int r_id();
	void add_wall(Direction to_add);

private:
	bool is_visited{ false };
	int id{ -1 };
	Patch * previous{};
	std::array<wall, 4>P_walls{};
};



Direction reverse_dir(Direction current_dir);