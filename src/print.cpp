/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: function to print a solution. It prints the permutation and cost
********************************************************************************************/

#include "Individual.h"
#include <iostream>
#include <fstream>
#include <string>

void Individual::print(const string &fileName) {
	ofstream f; //Creacion de fichero logico para la escritura en el fichero
	f.open(fileName, ios::app);
	if (!f)
		cout << "Error opening the file" << endl;
	else{
		f << "Solution: ";
		for(int i=0; i< problem->problemDimension;i++){
			f << S[i] << " ";
		}
		f<< endl;
		f<< "Cost: "<< cost<< endl;
		f.close();
	}
}
