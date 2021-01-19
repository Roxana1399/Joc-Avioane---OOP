#include "Tabla_Joc.h"
#include <fstream>
#include <time.h>

/* Folosit pentru computer */
Tabla_Joc::Tabla_Joc(int k)
{
	setEmptyTable();
	makeTable(k);
}

Tabla_Joc::Tabla_Joc()
{
	//setEmptyTable();
	//makeTable();
}

Tabla_Joc::~Tabla_Joc()
{

}

/* Initializare tabla */
void Tabla_Joc::setEmptyTable()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			matrix[i][j] = 0;
}

/* Seteaza elementele tablei */
void Tabla_Joc::makeTable(int k)
{
	srand(time(0));
	int x[10] = { 0 };
	int y[10] = { 0 };

	/* Pentru vertical */
	for (int i = 0; i < k; i++)
	{
		x[i] = rand() % 7; // linii de la 0 la 6
		y[i] = rand() % 6 + 2; // coloane de la 2 la 7
	}

	int posX, posY;

	for (int i = 0; i < k; i++)
	{
		/* 0 - vertical, 1 - orizontal */
		int randomOrientation = rand() % 2;
		// Daca e orientat orizontal schimbam pozitiile
		if (randomOrientation == 1)
		{
			x[i] = rand() % 6 + 2; // linii intre 2 si 7
			y[i] = rand() % 7 + 3; // coloane intre 3 si 9
		}

		posX = x[i];
		posY = y[i];

		if (randomOrientation == 0)
		{
			// Pozitie verticala
			if (addAvion(x[i], y[i], posX, posY))
			{
				addAvionUtil(posX, posY);
			}
		}
		else if (randomOrientation == 1)
		{	
			//pozitie verticala
			if (addAvion2(x[i], y[i], posX, posY))
			{
				addAvionUtil2(posX, posY);
			}
		}
	}


}

/* Afisare tabla */
void Tabla_Joc::printTable()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << matrix[i][j] << ' ';

		cout << '\n';
	}
}

// vertical
void Tabla_Joc::addAvionUtil(int x, int y)
{
	matrix[x][y] = 2; /* pentru capul avionului */

	for (int i = 1; i < 4; i++)
		matrix[x + i][y] = 1;

	matrix[x + 3][y - 1] = 1;
	matrix[x + 3][y + 1] = 1;
	
	for (int i = -2; i <= 2; i++)
		matrix[x + 1][y + i] = 1;
}

// orizontal
void Tabla_Joc::addAvionUtil2(int x, int y)
{
	matrix[x][y] = 2; /* pentru capul avionului */
	matrix[x][y - 1] = 1;
	matrix[x - 1][y - 1] = 1;
	matrix[x + 1][y - 1] = 1;
	matrix[x][y - 2] = 1;
	matrix[x][y - 3] = 1;
	matrix[x - 1][y - 3] = 1;
	matrix[x + 1][y - 3] = 1;
	matrix[x - 2][y - 1] = 1;
	matrix[x + 2][y - 1] = 1;
}

int Tabla_Joc::addAvion(int x, int y, int &posX, int &posY)
{
	int x1, y1;

	if (!(matrix[x][y] != 0 || matrix[x + 1][y - 2] != 0 || matrix[x + 1][y - 1] != 0 || matrix[x + 1][y] != 0 ||
		matrix[x + 1][y + 1] != 0 || matrix[x + 1][y + 2] != 0 || matrix[x + 2][y] != 0 || matrix[x + 3][y - 1] != 0 ||
		matrix[x + 3][y] != 0 || matrix[x + 3][y + 1] != 0))
	{
		posX = x;
		posY = y;
		return true;
	}

	for (int i = -10; i < 10; i++)
	{
		for (int j = -10; j < 10; j++)
		{
			/* Verificam daca a iesit capul avionului din tabla */
			if (x + i < 0 || x + i > 6 || y + j < 2 || y + j > 7)
				continue;

			x1 = x + i;
			y1 = y + j;

			if (!(matrix[x1][y1] != 0 || matrix[x1 + 1][y1 - 2] != 0 || matrix[x1 + 1][y1 - 1] != 0 || matrix[x1 + 1][y1] != 0 ||
				matrix[x1 + 1][y1 + 1] != 0 || matrix[x1 + 1][y1 + 2] != 0 || matrix[x1 + 2][y1] != 0 || matrix[x1 + 3][y1 - 1] != 0 ||
				matrix[x1 + 3][y1] != 0 || matrix[x1 + 3][y1 + 1] != 0))
			{
				posX = x1;
				posY = y1;
				return true;
			}
		}
	}

	return false;
}

int Tabla_Joc::addAvion2(int x, int y, int &posX, int &posY)
{
	int x1, y1;

	if (!(matrix[x][y] != 0 || matrix[x][y - 1] != 0 || matrix[x - 1][y - 1] != 0 || matrix[x + 1][y - 1] != 0 ||
		matrix[x][y - 2] != 0 || matrix[x][y - 3] != 0 || matrix[x - 1][y - 3] != 0 || matrix[x + 1][y - 3] != 0 ||
		matrix[x - 2][y - 1] != 0 || matrix[x + 2][y - 1] != 0))
	{
		posX = x;
		posY = y;
		return true;
	}

	for (int i = -10; i < 10; i++)
	{
		for (int j = -10; j < 10; j++)
		{
			if (x + i < 2 || x + i > 7 || y + j < 3 || y + j > 9)
				continue;

			x1 = x + i;
			y1 = y + j;

			if (!(matrix[x1][y1] != 0 || matrix[x1][y1 - 1] != 0 || matrix[x1 - 1][y1 - 1] != 0 || matrix[x1 + 1][y1 - 1] != 0 ||
				matrix[x1][y1 - 2] != 0 || matrix[x1][y1 - 3] != 0 || matrix[x1 - 1][y1 - 3] != 0 || matrix[x1 + 1][y1 - 3] != 0 ||
				matrix[x1 - 2][y1 - 1] != 0 || matrix[x1 + 2][y1 - 1] != 0))
			{
				posX = x1;
				posY = y1;
				return true;
			}
		}
	}

	return false;

}
/*
Varianta recursiva la care e STACK OVERFLOW
int Tabla_Joc::addAvion(int x, int y, int &posX, int &posY)
{
	if (x < 0 || x > 6 || y < 2 || y > 7)
		return false;

	if (matrix[x][y] != 0 || matrix[x + 1][y - 2] != 0 || matrix[x + 1][y - 1] != 0 || matrix[x + 1][y] != 0 ||
		matrix[x + 1][y + 1] != 0 || matrix[x + 1][y + 2] != 0 || matrix[x + 2][y] != 0 || matrix[x + 3][y - 1] != 0 ||
		matrix[x + 3][y] != 0 || matrix[x + 3][y + 1] != 0)
	{
		if (addAvion(x - 1, y - 1, posX, posY))
		{
			posX = x - 1;
			posY = y - 1;
			return true;
		}
		else if (addAvion(x - 1, y, posX, posY))
		{
			posX = x - 1;
			posY = y;
			return true;
		}
		else if (addAvion(x, y - 1, posX, posY))
		{
			posX = x;
			posY = y - 1;
			return true;
		}
		else if (addAvion(x, y + 1, posX, posY))
		{
			posX = x;
			posY = y + 1;
			return true;
		}
		else if (addAvion(x + 1, y, posX, posY))
		{
			posX = x + 1;
			posY = y;
			return true;
		}
		else if (addAvion(x + 1, y + 1, posX, posY))
		{
			posX = x + 1;
			posY = y + 1;
			return true;
		}

	}
	else
		return true;

	return false;
}*/


void Tabla_Joc::setElemPos(int rand, int coloana, int val)
{
	this->matrix[rand][coloana] = val;
}

bool Tabla_Joc::distrus()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (this->matrix[i][j] != 0)
				return false;

	return true;
}

int Tabla_Joc::getElemPos(int rand, int coloana)
{
	return this->matrix[rand][coloana];
}