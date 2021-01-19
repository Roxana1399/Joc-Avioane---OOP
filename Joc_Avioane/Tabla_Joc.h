#ifndef TABLA_JOC_H

#define TABLA_JOC_H

#include <iostream>
#include <cstring>

using namespace std;

class Tabla_Joc {

protected:
	int matrix[10][10];
	void makeTable(int k);
	void setEmptyTable();
	void addAvionUtil(int x, int y);
	void addAvionUtil2(int x, int y);

public:
	Tabla_Joc();
	Tabla_Joc(int k);
	Tabla_Joc(int k, string fileName);
	~Tabla_Joc();

	void printTable();
	int addAvion(int x, int y, int &posX, int &posY);
	int addAvion2(int x, int y, int &posX, int &posY);
	int getElemPos(int x, int y);
	void setElemPos(int x, int y, int val);
	bool distrus();


};

#endif TABLA_JOC_H

