#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> maliste;

	for (int i = 0; i < 30; ++i) {
		maliste.push_back(2 * i + 1);
	}
	cout << "Contenu de la liste avant : ";
	for (int n : maliste) {
		cout << n << " ";
	}
	
	cout << endl;
	list<int>::iterator it = maliste.begin();
	advance(it, 2);
	maliste.erase(it);
	cout << "Contenu de la liste apres : ";

	for (int n : maliste) {
		cout << n << " ";
	}
	cout << endl;

	cout << "Avant ajout des 20 suivants : ";
	for (int n : maliste) cout << n << " ";
	cout << endl;

	for (int i = 30; i < 50; ++i) {  
		maliste.push_back(2 * i + 1);
	}

	cout << "Apres ajout des 20 suivants : ";
	for (int n : maliste) cout << n << " ";
	cout << endl;

	

	return 0;
}
