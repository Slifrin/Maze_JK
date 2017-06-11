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

void Patch::remove_wall()
{

}

void Patch::make_visited(int id)
{
	is_visited = true;
}

bool Patch::check_if_visited()
{
	return is_visited;
}


void wall::disappear()
{
	exist = false;
}

bool wall::is_w_ther()
{
	return exist;
}
