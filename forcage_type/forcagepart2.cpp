#include <iostream>
#include <vector>
using namespace std;

int main() {
	int taille;
	cout << "Entrez la taille ex 2 : ";
	cin >> taille;

	vector<int> n;
	n.reserve(taille);

	
	for (int i = 0; i < taille; i++) {
		float notef;
		cout << "Nombre pour ligne" << i + 1 << endl;
		cin >> notef;
		n.push_back(static_cast<int>(notef));
	}
	for (int i = 0; i < taille; i++) {
		cout << "nombre en int " << i + 1 << " : "<< n[i] << endl;
	}
	return 0;
}
