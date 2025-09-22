#include <iostream>
#include "Calc.h"


int main()
{
	Calculatrice<int> calcInt(10, 3);
	calcInt.afficherResultats();

	Calculatrice<float> calcFloat(5.5, 2.2);
	calcFloat.afficherResultats();

	Calculatrice<double> calcdouble(143.236, 323.923);
	calcdouble.afficherResultats();


}
