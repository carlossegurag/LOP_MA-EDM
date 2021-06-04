/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: loader of LOP instances
********************************************************************************************/

#include "Problem.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

//Load instance
Problem::Problem(const string &fileName){
	LOPMatrix initialMatrix;
	int i = 0, size_m, val;
	ifstream f; 
	f.open(fileName);
	if(!f){
 		cout << "Error opening the instance file" << endl;
		exit(-1);
	}else{
		f >> size_m; 
		while(i<size_m){
			vector <int> tmp;
			for (int j = 1; j <= size_m; j++) {
				f >> val;
				tmp.push_back(val);
			}
			initialMatrix.push_back(tmp);
			++i;
		}
		f.close(); 
	}
	problemDimension=size_m;
	instance=initialMatrix;
}
