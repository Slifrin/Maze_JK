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

void Patch::make_visited(int n_id)
{
	id = n_id;
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

bool Patch::is_wall_ther(Direction current_dir)
{
	//return P_walls[int(current_dir)].is_w_ther();
	bool wall_info{ false };
	switch (current_dir)
	{
	case Direction::top:
		wall_info = P_walls[0].is_w_ther();
		break;
	case Direction::bottom:
		wall_info = P_walls[1].is_w_ther();
		break;
	case Direction::left:
		wall_info = P_walls[2].is_w_ther();
		break;
	case Direction::right:
		wall_info = P_walls[3].is_w_ther();
		break;
	default:
		break;
	}
	return wall_info;
}

int Patch::r_id()
{
	return id;
}

void Patch::add_wall(Direction to_add)
{
	switch (to_add)
	{
	case Direction::top:
		P_walls[0].appear();
		break;
	case Direction::bottom:
		P_walls[1].appear();
		break;
	case Direction::left:
		P_walls[2].appear();
		break;
	case Direction::right:
		P_walls[3].appear();
		break;
	default:
		break;
	}
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
