/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: implementation of the cycle-based crossover (CX)
********************************************************************************************/

#include "Individual.h"
#include "utils.h"

//At exit, both individuls must have been evaluated 
void Individual::crossoverCX(Individual &ind) {
	//Calculate inverted indexes
	int valueToPositionI1[problem->problemDimension];
	calculateInvertedIndexes(valueToPositionI1);
	int valueToPositionI2[problem->problemDimension];
	ind.calculateInvertedIndexes(valueToPositionI2);
	//clone this because is going to change
	Individual copyI1 = internalClone();
	crossoverCXone(ind, valueToPositionI1, valueToPositionI2);
	ind.crossoverCXone(copyI1, valueToPositionI2, valueToPositionI1);
}

void Individual::crossoverCXone(Individual &ind, int *valueToPositionI1, int *valueToPositionI2) {
	long int i, si, vi;
	int EMPTY_VAL = (-1);
	int NewInd[problem->problemDimension];
	bzero(NewInd, problem->problemDimension * sizeof(int));

	//Copy matching positions
	for (i = 0; i < problem->problemDimension; i++) {
		if (S[i] == ind.S[i]) 
			NewInd[i] = ind.S[i];
		else 
			NewInd[i] = EMPTY_VAL;
	}

	si = getRandomInteger0_N(problem->problemDimension);
	for (vi = si; vi < si + problem->problemDimension; vi++) {
		i = vi % problem->problemDimension;
		if (NewInd[i] < 0) {
			//Select one of the cycles randomly
			int j, p, k;
			p = getRandomInteger0_N(2);
			j = i;
			do {//Copy cycle
				if (p == 0) {
					NewInd[j] = S[j];
					k = ind.S[j];
					j = valueToPositionI1[k];
				} else {
					NewInd[j] = ind.S[j];
					k = S[j];
					j = valueToPositionI2[k];
				}
			} while (j != i);
		}
	}

	//Apply to the individual and evaluate
	for(i=0 ; i< problem->problemDimension ; i++){
		S[i]=NewInd[i];
	}
	evaluate();
}

void Individual::calculateInvertedIndexes(int *indexes){
	for (unsigned int i = 0; i < problem->problemDimension; i++){
		indexes[S[i]] = i;
	}
}
