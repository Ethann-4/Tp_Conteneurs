#include <iostream>
#include "Temps.h"

int main() {
	Temps t1(1, 75, 90);   
	Temps t2(0, 59, 125);  

	std::cout << "Avec afficher() :" << std::endl;
	t1.afficher();
	t2.afficher();

	std::cout << "Avec operator<< :" << std::endl;
	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;

	return 0;
}
