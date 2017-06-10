#pragma once
#include <vector>
#include "Patch.h"
class Maze
{
public:
	Maze();
	~Maze();

private:
	int width;
	int length;
	std::vector<Patch> field;
};

