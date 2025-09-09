#include <iostream>
#include <vector>

using namespace std;

struct Operation {
	int numero;
	int quantite;
};

void saisirOperations(vector<Operation>& operations, int nbOperations) {
	for (int i = 0; i < nbOperations; i++) {
		Operation opera;
		cin >> opera.numero >> opera.quantite;
		operations.push_back(opera);
	}
}

void calculerStock(vector<Operation>& operations, vector<int>& Stock) {
	Stock.assign(10, 0);
	for (Operation& opera : operations) {
		Stock[opera.numero - 1] += opera.quantite;
	}

}
void afficherStock(vector<int>& Stock) {
	for (int i = 0; i < 10; i++) {
		cout << Stock[i] << endl;
	}
		

}

int main()
{
	int nbOperations;
	cin >> nbOperations;
	
	vector<int> Stock;
	vector<Operation> operations;

	saisirOperations(operations, nbOperations);
	calculerStock(operations, Stock);
	afficherStock(Stock);

	return 0;

}
