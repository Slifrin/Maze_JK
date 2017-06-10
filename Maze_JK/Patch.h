#pragma once
#include <iostream>
class Patch
{
public:
	Patch();
	~Patch();

	void spr_wsk();
private:
	bool is_visited{ false };
	int id{ -1 };
	Patch * previous{};
};

