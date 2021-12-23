/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: main function to execute MA-EDM to an instance.
Parameters:
- Number of individuals in the population
- Crossover: it can be cx or ob
- Stopping criterion in time
- Seed
- Instance file
- Output file
********************************************************************************************/


#include "MA.h"
#include <unistd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>

Problem *Individual::problem;
int main(int argc, char **argv){
	if(argc!=7){
		cout << "Error. Usage: " << argv[0] << " N crossover stopping_criterion seed instance_file output_file" << endl; 
		exit(0);
	}
	int N = atoi(argv[1]);
	double pc = 1.0;
	string crossType = argv[2];
	double finalTime = atof(argv[3]);
	int seed = atoi(argv[4]);
	string instanceFile = argv[5];
	string outputFile = argv[6];

	srand(seed);
	MA ma(N, pc, crossType, finalTime, outputFile);
	Problem p(instanceFile);
	Individual::problem = &p;
	ma.run();
}
