#include "Game.h"
#include <time.h>

Game::Game(Tabla_Joc_File g, Tabla_Joc c)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			this->gamer.setElemPos(i, j, g.getElemPos(i, j));

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			this->computer.setElemPos(i, j, c.getElemPos(i, j));

	while (!endJoc())
	{
		int rand; int coloana; 
		cout << "Jucator:  " << endl;
		cout << "r:"; cin >> rand;
		cout << "c:"; cin >> coloana;
		mutareGamer(rand, coloana);

		int r = randomNr1();
		int c = randomNr2();
		cout << "Computer: linie:  " << r << " coloana: " << c << endl;
		mutareComputer(r, c);
	}

	castigator();
}

bool Game::endJoc()
{
	if ((this->gamer.distrus() == true) || (this->computer.distrus() == true))
		return true;
	else return false;
}

void Game::castigator()
{
	if (this->gamer.distrus() == true) 
		cout << "Computer-ul a castigat! " << '\n';
	if (this->computer.distrus() == true) 
		cout << " Ati castigat! " << '\n';
}

void Game::mutareGamer(int rand, int coloana)
{
	if (this->gamer.getElemPos(rand, coloana) == 0)
		cout << "aer" << '\n';

	if (this->gamer.getElemPos(rand, coloana) == 1)
	{
		cout << "lovit" << '\n';

		/* Distrugem bucata de avion */
		this->gamer.setElemPos(rand, coloana, 0);
	}

	if (this->gamer.getElemPos(rand, coloana) == 2)
	{
		cout << "distrus" << '\n';

		/* Daca e amplasat orizontal */
		if (this->gamer.getElemPos(rand, coloana - 1) == 1 && this->gamer.getElemPos(rand - 1, coloana - 1) == 1 &&
			this->gamer.getElemPos(rand - 2, coloana - 1) == 1 && this->gamer.getElemPos(rand + 1, coloana - 1) == 1 &&
			this->gamer.getElemPos(rand + 2, coloana - 1) == 1 && this->gamer.getElemPos(rand, coloana - 2) == 1 &&
			this->gamer.getElemPos(rand, coloana - 3)== 1 && this->gamer.getElemPos(rand - 1, coloana - 3) == 1 &&
			this->gamer.getElemPos(rand + 1, coloana - 3) == 1)
		{
			this->gamer.setElemPos(rand, coloana, 0);
			this->gamer.setElemPos(rand, coloana - 1, 0);
			this->gamer.setElemPos(rand - 1, coloana - 1, 0);
			this->gamer.setElemPos(rand - 2, coloana - 1, 0);
			this->gamer.setElemPos(rand + 1, coloana - 1, 0);
			this->gamer.setElemPos(rand + 2, coloana - 1, 0);
			this->gamer.setElemPos(rand    , coloana - 2, 0);
			this->gamer.setElemPos(rand    , coloana - 3, 0);
			this->gamer.setElemPos(rand - 1, coloana - 3, 0);
			this->gamer.setElemPos(rand + 1, coloana - 3, 0);
		}
		else
		{
			/* Daca e amplasat vertical */
			this->gamer.setElemPos(rand, coloana, 0);
			this->gamer.setElemPos(rand + 1, coloana - 2, 0);
			this->gamer.setElemPos(rand + 1, coloana - 1, 0);
			this->gamer.setElemPos(rand + 1, coloana + 0, 0);
			this->gamer.setElemPos(rand + 1, coloana + 1, 0);
			this->gamer.setElemPos(rand + 1, coloana + 2, 0);
			this->gamer.setElemPos(rand + 2, coloana + 0, 0);
			this->gamer.setElemPos(rand + 3, coloana - 1, 0);
			this->gamer.setElemPos(rand + 3, coloana + 0, 0);
			this->gamer.setElemPos(rand + 3, coloana + 1, 0);
		}


	}
}

void Game::mutareComputer(int rand, int coloana)
{
	// this->gamer.printTable();

	cout << endl;
	if (this->gamer.getElemPos(rand, coloana) == 0)
		cout << "aer" << '\n';

	if (this->gamer.getElemPos(rand, coloana) == 1)
	{
		cout << "lovit" << '\n';

		/* Distrugem bucata de avion */
		this->gamer.setElemPos(rand, coloana, 0);
	}

	if (this->gamer.getElemPos(rand, coloana) == 2)
	{
		cout << "distrus" << '\n';

		/* Daca e amplasat orizontal */
		if (this->gamer.getElemPos(rand, coloana - 1) == 1 && this->gamer.getElemPos(rand - 1, coloana - 1) == 1 &&
			this->gamer.getElemPos(rand - 2, coloana - 1) == 1 && this->gamer.getElemPos(rand + 1, coloana - 1) == 1 &&
			this->gamer.getElemPos(rand + 2, coloana - 1) == 1 && this->gamer.getElemPos(rand, coloana - 2) == 1 &&
			this->gamer.getElemPos(rand, coloana - 3) == 1 && this->gamer.getElemPos(rand - 1, coloana - 3) == 1 &&
			this->gamer.getElemPos(rand + 1, coloana - 3) == 1)
		{
			this->gamer.setElemPos(rand, coloana, 0);
			this->gamer.setElemPos(rand, coloana - 1, 0);
			this->gamer.setElemPos(rand - 1, coloana - 1, 0);
			this->gamer.setElemPos(rand - 2, coloana - 1, 0);
			this->gamer.setElemPos(rand + 1, coloana - 1, 0);
			this->gamer.setElemPos(rand + 2, coloana - 1, 0);
			this->gamer.setElemPos(rand, coloana - 2, 0);
			this->gamer.setElemPos(rand, coloana - 3, 0);
			this->gamer.setElemPos(rand - 1, coloana - 3, 0);
			this->gamer.setElemPos(rand + 1, coloana - 3, 0);
		}
		else
		{
			/* Daca e amplasat vertical */
			this->gamer.setElemPos(rand, coloana, 0);
			this->gamer.setElemPos(rand + 1, coloana - 2, 0);
			this->gamer.setElemPos(rand + 1, coloana - 1, 0);
			this->gamer.setElemPos(rand + 1, coloana + 0, 0);
			this->gamer.setElemPos(rand + 1, coloana + 1, 0);
			this->gamer.setElemPos(rand + 1, coloana + 2, 0);
			this->gamer.setElemPos(rand + 2, coloana + 0, 0);
			this->gamer.setElemPos(rand + 3, coloana - 1, 0);
			this->gamer.setElemPos(rand + 3, coloana + 0, 0);
			this->gamer.setElemPos(rand + 3, coloana + 1, 0);
		}
	}
	
}

int Game::randomNr1()
{
	int x1 = rand() % 9 + 0;
	return x1;
}

int Game::randomNr2()
{
	int x2 = rand() % 9 + 0;
	return x2;
}
