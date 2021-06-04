/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: function to evaluate the cost associated to a permutation
********************************************************************************************/

#include "Individual.h"

void Individual::evaluate() {
	cost = 0;
	for (unsigned int j = 0; j < problem->problemDimension - 1; j++){
		for (unsigned int i = j+1; i < problem->problemDimension; i++){
			cost += problem->instance[S[j]][S[i]];
		}
	}
}
