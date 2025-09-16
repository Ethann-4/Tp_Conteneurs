#include <iostream>
#include <vector>
using namespace std;

class Note {
public:
	virtual void afficher() {
		cout << "Note générique" << endl;
	}
};

class NoteSur20 : 
	
	public Note {
	float valeur;

public:
	NoteSur20(float v) : valeur(v) {}

	void afficher() override {
		cout << "Note sur 20 : " << valeur << endl; 
	}

	float getValeur() {
		return valeur; 
	}
};

int main() {

	NoteSur20 manote(15.5);
	Note* pointnote = &manote;

	cout << "appel avec ";
	pointnote->afficher();

	NoteSur20* pointnote20 = static_cast<NoteSur20*>(pointnote);

	cout << "afficher avec la note reel avec static cast : " << pointnote20->getValeur() << endl;

	
	return 0;
}
