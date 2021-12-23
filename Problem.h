/*******************************************************************************************
Authors: Carlos Segura (Programmer and Designer), Lazaro Lugo (Programmer and Designer),
Gara Miranda (Designer)

Description: class to store the information of a LOP instance
********************************************************************************************/

#ifndef __PROBLEM_H__
#define __PROBLEM_H__

#include <vector>
#include <string>
#define LOPMatrix vector<vector<int>>
using namespace std;

class Problem {
	public:
		Problem(const string &fileName);
		~Problem(){ }
		LOPMatrix instance;
		int problemDimension;
};

#endif
