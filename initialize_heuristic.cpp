/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: initialization of solutions. No heuristic is used in this case; instead
each permutation is equiprobable.
********************************************************************************************/

#include "Individual.h"
#include <algorithm>

void Individual::initialize_heuristic() {
	for (int i = 0; i < problem->problemDimension; i++) {
		S.push_back(i);
	}
	random_shuffle(S.begin(), S.end());
	evaluate();
}
