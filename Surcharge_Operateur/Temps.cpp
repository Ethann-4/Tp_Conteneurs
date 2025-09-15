#include "Temps.h"
#include <iomanip>

using namespace std;

Temps::Temps(int heures, int minutes, int secondes)
	: m_heures(heures), m_minutes(minutes), m_secondes(secondes) {
	conversion();
}



void Temps::conversion()
{
	if (m_secondes >= 60) {
		m_minutes += m_secondes / 60;
		m_secondes %= 60;
	}
	else if (m_minutes < 0) {
		int autre = (m_secondes + 59) / 60;
		m_minutes -= autre;
		m_secondes += autre * 60;
	}

	if (m_minutes >= 60) {
		m_heures += m_minutes / 60;
		m_minutes %= 60;
	}
	else if (m_minutes < 0) {
		int autre = (m_minutes + 59) / 60;
		m_heures -= autre;
		m_minutes += autre * 60;
	}
}

void Temps::afficher() {
	cout << m_heures << ":" << m_minutes << ":" << m_secondes << endl;
}

ostream& operator<<(std::ostream & os, Temps & t){
	os << t.m_heures << ":" << t.m_minutes << ":" << t.m_secondes;
	return os;
}
