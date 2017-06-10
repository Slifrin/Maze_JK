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
}

void Patch::make_visited()
{
	is_visited = true;
}

bool Patch::check_if_visited()
{
	return is_visited;
}
