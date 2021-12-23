/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: function to calculate the permutation deviation distance of two permutations
********************************************************************************************/

#include "Individual.h"

TDistance Individual::getDistance(Individual &ind) {
	int valueToPositionI2[problem->problemDimension];
	for(int i=0; i < problem->problemDimension; i++){
		valueToPositionI2[ind.S[i]] = i;
	}

	int contPar = 0;
	for(int i=0; i < (problem->problemDimension); i++){
		contPar += abs(i - valueToPositionI2[S[i]]);
	}
	return contPar;
}
