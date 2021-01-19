#ifndef GAME_H
#define GAME_H
#include "Tabla_Joc.h"
#include"Tabla_Joc_File.h"

class Game {
private:
	Tabla_Joc_File gamer;
	Tabla_Joc computer;
public:
	Game(Tabla_Joc_File g, Tabla_Joc c);
	~Game() {};
	bool endJoc();
	void castigator();
	void mutareGamer(int rand, int coloana);
	void mutareComputer(int rand, int coloana);
	int randomNr1();
	int randomNr2();
};

#endif
