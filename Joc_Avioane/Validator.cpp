
#include "Validator.h"

void validareMatrice(int a[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (a[i][j] >= 3 || a[i][j] <= -1)
				throw MyException("Matrice invalida");
}
void validareNrAvioane(int k)
{
	if (k < 1 || k >= 4)
		throw MyException("Numar de avioane incorect");
}