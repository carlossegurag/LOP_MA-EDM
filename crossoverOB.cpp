/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: implementation of the order-based crossover (OB)
********************************************************************************************/

#include "Individual.h"
#include "utils.h"

//At exit, both individuls must have been evaluated 
void Individual::crossoverOB(Individual &ind) {
	//Save first individual
	int copyInd1[problem->problemDimension];
	for (int i = 0; i < problem->problemDimension; i++){
		copyInd1[i] = S[i];
	}

	//Save second individual
	int copyInd2[problem->problemDimension];
	for (int i = 0; i < problem->problemDimension; i++){
		copyInd2[i] = ind.S[i];
	}

	//Select the positions that are going to change
	bool selected1[problem->problemDimension];
	bool selected2[problem->problemDimension];
	bzero(selected1, sizeof(selected1));
	bzero(selected2, sizeof(selected2));
	for (int i = 0; i < problem->problemDimension / 2; i++){//Select about problemDimension/2 positions. 
		selected1[getRandomInteger0_N(problem->problemDimension -1)] = true;
	}
	for (int i = 0; i < problem->problemDimension / 2; i++){
		selected2[getRandomInteger0_N(problem->problemDimension -1)] = true;
	}

	//Mark the values that are going to be changed
	bool selected1V[problem->problemDimension], selected2V[problem->problemDimension];
	bzero(selected1V, sizeof(selected1V));
	bzero(selected2V, sizeof(selected2V));
	for (int i = 0; i < problem->problemDimension; i++){
		if (selected1[i]){
			selected1V[copyInd1[i]] = true;
		}
		if (selected2[i]){
			selected2V[copyInd2[i]] = true;
		}
	}

	//Store the indexes that are going to be changed (sorted)
	vector < int > selectedIndexes1, selectedIndexes2;
	for (int i = 0; i < problem->problemDimension; i++){
		if (selected1[i]){
			selectedIndexes1.push_back(i);
		}
		if (selected2[i]){
			selectedIndexes2.push_back(i);
		}
	}

	//Move the values in sorted order to the first individual
	int copied = 0;
	for (int i = 0; i < problem->problemDimension; i++){
		if (selected1V[copyInd2[i]]){
			S[selectedIndexes1[copied]]=copyInd2[i];
			copied++;
		}
	}
	
	//Move the values in sorted order to the second individual
	copied = 0;
	for (int i = 0; i < problem->problemDimension; i++){
		if (selected2V[copyInd1[i]]){
			ind.S[selectedIndexes2[copied]]=copyInd1[i];
			copied++;
		}
	}

	//Evaluate both offspring
	evaluate();
	ind.evaluate();
}

