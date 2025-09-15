#pragma once
#include <iostream>
class Temps {
private:
	int m_heures;
	int m_minutes;
	int m_secondes;

	void conversion();
public:
	Temps(int heures = 0.0, int minutes = 0.0, int secondes = 0.0);

	void afficher() ;

	friend std::ostream& operator<<(std::ostream& os, Temps& t);
};


