#ifndef AVION_H
#define AVION_H

class Piesa
{
private:
	int rand;
	int coloana;
public:
	Piesa();
	~Piesa();


};


class Avion : public Piesa
{
public: 
	Avion()
	{
		this->rand = this->coloana = 0;
	}
	~Avion() { }
	int getColoana()
	{
		return this->coloana;
	}
	int getRand()
	{
		return this->rand;
	}
};

#endif
