#pragma once
#include <iostream>
class Patch
{
public:
	Patch();
	~Patch();

	void spr_wsk();
	void make_visited();
	bool check_if_visited();
private:
	bool is_visited{ false };
	int id{ -1 };
	Patch * previous{};
};

