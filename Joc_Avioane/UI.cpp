#include "UI.h"
#include"Validator.h"

#include <iostream>
using namespace std;

void UI::printMenu()
{
	cout << "1) Incepe jocul\n";
	cout << "2) Iesire\n";
}

void UI::startJoc(int k)
{
	/* Creare tabla joc pentru computer */
	Tabla_Joc computer = Tabla_Joc(k);
	cout << "Tabla joc computer" << endl;
	computer.printTable(); /* Afisam tabla de joc pentru computer */
	cout << '\n';

	/* Creare tabla joc pentru jucator */
	Tabla_Joc_File gamer;

	if (k == 1)
	{
		gamer = Tabla_Joc_File(k, "avion1.txt");
		cout << "Tabla joc gamer"<<endl;
		gamer.printTable();
	}

	else if (k == 2)
	{
		gamer = Tabla_Joc_File(k, "avion2.txt");
		cout << "Tabla joc gamer"<<endl;
		gamer.printTable();
	}

	else if (k == 3)
	{
		gamer = Tabla_Joc_File(k, "avion3.txt");
		cout << "Tabla joc gamer"<<endl;
		gamer.printTable();
	}

	Game joc = Game(gamer, computer);
}

void UI::run()
{
	int k;
	
	do
	{
		cout << "Dati numarul de avioane pe care vreti sa le plasati (numar intre 1 si 3): ";
		cin >> k;

	} while (k < 1 || k > 3);
	

	cout << "Dati coordonate (linie, coloana) de la 0 la 9. Jocul se incheie cand unul din jucatori distruge toate avioanele adversarului (sau nimereste varful tuturor avioanelor) " << endl;
	
	int x = 0;
	int op;

	while (x == 0)
	{
		printMenu();
		cout << "Introduceti optiunea: " << endl;
		cin >> op;
		switch (op)
		{
			case 1:
			{
				cout << "Incepe jocul! " << endl;
				startJoc(k);
				cout << "Jocul s-a sfarsit! " << endl;
				break;
			}
			default:
			{
				cout << "Multumim ca ati jucat!" << endl;
				x = 1;
				break;
			}
		}
	}
}