#pragma once
#include"Tabla_Joc.h"
#include <iostream>
#include <fstream>
#include <istream>
#include "Validator.h"
using namespace std;

class Tabla_Joc_File : public Tabla_Joc {
private:
	string fileName1;
	string fileName2;
	string fileName3;
public:
	/*
Citirea tablei

0 - cod succes
1 - cod eroare k incorect
2 - cod eroare deschidere fisier
*/
	int readMatrix(int k)
	{
		ifstream fin;

		/* Nu s-a introdus un numar corect de avioane */
		if (k <= 0 || k >= 4)
			return 1;

		if (k == 1)
			fin.open(this->fileName1);
		else if (k == 2)
			fin.open(this->fileName2);
		else if (k == 3)
			fin.open(this->fileName3);

		/* Daca nu s-a reusit deschierea fisierului */
		if (!fin)
		{
			cout << "Eroare la deschiderea fisierului\n";
			return 2;
		}

		/* Citire elemente matrice */
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fin >> this->matrix[i][j];
			}
		}


		fin.close();

		return 0; /* success */
	}
	/* constrctorul cu parametrii*/
	Tabla_Joc_File(int k, string fileName)
	{
		setEmptyTable();

		if (k == 1)
			this->fileName1 = fileName;

		if (k == 2)
			this->fileName2 = fileName;

		if (k == 3)
			this->fileName3 = fileName;

		readMatrix(k);
		validareMatrice(this->matrix);
		
	}

	Tabla_Joc_File(int k)
	{
		setEmptyTable();
		makeTable(k);
	}

	Tabla_Joc_File()
	{
		//setEmptyTable();
		//makeTable();
	}
	void setEmptyTable()
	{
		Tabla_Joc::setEmptyTable();

	}
	void makeTable(int k)
	{
		Tabla_Joc::makeTable(k);
	}
	void setElemPos(int x, int y, int val)
	{
		Tabla_Joc::setElemPos(x, y, val);
	}
	bool distrus()
	{
		return Tabla_Joc::distrus();
	}
	int getElemPos(int x, int y)
	{
		return Tabla_Joc::getElemPos(x, y);

	}
	~Tabla_Joc_File()
	{

	}
	void addAvionUtil(int x, int y)
	{
		Tabla_Joc::addAvionUtil(x, y);
	}

	void addAvionUtil2(int x, int y)
	{
		Tabla_Joc::addAvionUtil2(x, y);
	}

	int addAvion(int x, int y, int &posX, int &posY)
	{
		return Tabla_Joc::addAvion(x, y, posX, posY);
	}

	int addAvion2(int x, int y, int &posX, int &posY)
	{
		return Tabla_Joc::addAvion2(x, y, posX, posY);
	}

};
