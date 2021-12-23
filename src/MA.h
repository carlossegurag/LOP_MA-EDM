/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: class for the Memetic Algorithm with Explicit Diversity Management (MA-EDM)
published in the paper "A Diversity-aware Memetic Algorithm for the Linear Ordering Problem"
********************************************************************************************/

#ifndef __MA_H__
#define __MA_H__

#include "Individual.h"

class MA {
	public:
		MA(int N_, double pc_,string &crossType_, double finalTime_, string &outputFile);
		void run();
	private:
		//Parameters of MA
		int N;//Population Size
		double pc;//crossover probability
		string crossType; //crossover type
		double finalTime;//Seconds
		string outputFile;

		//Basic procedures of MA
		void initPopulation();
		void initDI();
		void selectParents();
		void crossover();
		void intensify();
		void replacement();

		//Internal attributes of MA
		vector< Individual * > population; 
		vector< Individual * > parents;
		vector< Individual * > offspring;
		double initialTime;
		double DI;
		int generation;
		double elapsedTime;
};

#endif
