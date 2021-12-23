/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: Individual class that is used by the MA-EDM solver. It is adapted to the 
Linear Ordering Problem, and considers two kinds of crossovers: CX and OB.
********************************************************************************************/

#ifndef __INDIVIDUAL_H__
#define __INDIVIDUAL_H__

#include <string>
#include <string.h>
#include <limits.h>
#include "Problem.h"
#define TFitness long long 
#define TDistance long long
#define MAX_DISTANCE LLONG_MAX

class Individual {
	public:
		Individual();
		~Individual(){};
		void initialize_heuristic();
		TDistance getDistance(Individual &ind);
		void crossoverCX(Individual &ind);//Cross both individuals (the result is saved in the individuals). Cycle Crossover
		void crossoverCXone(Individual &ind, int *valueToPositionI1, int *valueToPositionI2);
		void crossoverOB(Individual &ind);//Cross both individuals (the result is saved in the individuals). Order based crossover
		void intensify();//Simple hill-climber
		static Problem *problem;
		void print(const string &fileName);
		void evaluate();
		void calculateInvertedIndexes(int *indexes);
		Individual internalClone();
		TDistance distance;
		TFitness getCost();
		vector<int> S;
	private:	
		TFitness cost;
};

#endif
