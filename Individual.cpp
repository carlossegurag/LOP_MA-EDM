/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: some internal operations required by MA:
- getCost as the negative of the cost because it is a maximization problem
- clone individuals
********************************************************************************************/

#include "Individual.h"

Individual::Individual(){
	S.resize(problem->problemDimension);
}

TFitness Individual::getCost(){
	return -cost;
}

Individual Individual::internalClone() {
	Individual tempInd;
	tempInd.S=S;
	tempInd.cost=cost;
	tempInd.distance=distance;
	tempInd.problem=problem;
	return tempInd;
}
