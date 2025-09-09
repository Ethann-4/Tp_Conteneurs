#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	
	map<string, float> facture;

	facture["Salade"] = 5.50;
	facture["Pizza"] = 12.00;
	facture["Pâtes"] = 8.75;
	facture["Steak"] = 15.20;
	facture["Dessert"] = 4.50;

	cout << "Contenu de la facture :" << endl;
	for (auto &plat : facture) {
		cout << plat.first << " : " << plat.second << " euro" << endl;
	}
	float total = 0.00;
	for (auto &plat : facture) {
		total += plat.second;
	}
	cout << "Le total est : " << total << endl;
}
