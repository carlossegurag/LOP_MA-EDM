/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: implementation of a stochatic hill-climber with the move operation. The whole
neighborhood is traversed in O(n^2).
********************************************************************************************/

#include "Individual.h"
#include <algorithm>

void Individual::intensify() {
	long int i, j, t, k, v, best_j;
	long int maxgain;
	best_j = 0;
	maxgain = 0;
	
	//Sort the indexes randomly to make it stochastic
	vector < int > vs;
	vs.reserve(problem->problemDimension);
	for (int i = 0; i < problem->problemDimension; i++) {
		vs.push_back(i);
	}
	random_shuffle(vs.begin(), vs.end());

	bool changed = true;
	while (changed) {
		changed = false;
		for (int indexv = 0; indexv < problem->problemDimension; indexv++) {
			//Select and value to move, and look for its best new position
			v = vs[indexv];
			long gain = 0;
			maxgain = 0;
			i = v;
			for (j = i - 1; j >= 0; j--) {//Move to the left
				gain += ((problem->instance[S[i]][S[j]]) - (problem->instance[S[j]][S[i]]));
				if (gain > maxgain) {
					maxgain = gain;
					best_j = j;
				}
			}

			gain = 0;
			for (j = i + 1; j < problem->problemDimension; j++) {//Move to the right
				gain += ((problem->instance[S[j]][S[i]]) - (problem->instance[S[i]][S[j]]));
				if (gain > maxgain) {
					maxgain = gain;
					best_j = j;
				}
			}

			if (maxgain > 0) {//If there is a gain, move it
				j = best_j;
				t = S[i];
				if (i < j)
					for (k = i + 1; k <= j; k++) {
						S[k - 1] = S[k];
					}
				else
					for (k = i - 1; k >= j; k--) {
						S[k + 1] = S[k];
					}
				S[j] = t;
				changed = true;
				cost += maxgain;
			}
		}
	}
}
