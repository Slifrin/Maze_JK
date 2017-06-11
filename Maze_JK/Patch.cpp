#include "Patch.h"


using namespace std;
Patch::Patch()
{
}


Patch::~Patch()
{
}

void Patch::spr_wsk()
{
	if (previous == nullptr) cout << "zainicjowany nullptr\n";
	for (auto i : P_walls)cout << i.is_w_ther() << endl;
}


void Patch::remove_wall(Direction to_remove)
{
	switch (to_remove)
	{
	case Direction::top:
		P_walls[0].disappear();
		break;
	case Direction::bottom:
		P_walls[1].disappear();
		break;
	case Direction::left:
		P_walls[2].disappear();
		break;
	case Direction::right:
		P_walls[3].disappear();
		break;
	default:
		break;
	}
}

void Patch::make_visited(int id)
{
	is_visited = true;
}

bool Patch::check_if_visited()
{
	return is_visited;
}

void Patch::p_id()
{
	cout << id;
}


void wall::disappear()
{
	exist = false;
}

void wall::appear()
{
	exist = true;
}

bool wall::is_w_ther()
{
	return exist;
}

Direction reverse_dir(Direction current_dir)
{
	Direction r_dir = Direction::none;
	switch (current_dir)
	{
	case Direction::top:
		r_dir = Direction::bottom;
		break;
	case Direction::bottom:
		r_dir = Direction::top;
		break;
	case Direction::left:
		r_dir = Direction::right;
		break;
	case Direction::right:
		r_dir = Direction::left;
		break;
	default:
		break;
	}

	return r_dir;
}
