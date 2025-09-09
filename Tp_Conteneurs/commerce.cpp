#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nbPersonnes;
	int nbProduits = 10;

	cin >> nbPersonnes;

	vector<int> produits(nbProduits, 0);

	for (int i = 0; i < nbPersonnes; i++) {
		int produitPrefere;
		cin >> produitPrefere;
		produits[produitPrefere]++;
	}

	for (int i = 0; i < nbProduits; i++) {
		cout << produits[i] << " ";
	}

	cout << endl;

	return 0;
}
