#include <iostream>


using namespace std;

int main() {
	const double conversion = 2.54; // nombre de cm pour un pouce (inch) 
	int longueur = 1; // longueur (en cm ou en in)
	char unite = 0; // ’c’ pour cm ou ’i’ pour inch
	cout << "Donnez une longueur suivi de l’unité (c ou i):\n";
	cin >> longueur >> unite;
	if (unite == ’i’)
		cout << longueur << " in == " << conversion * longueur << " cm\n";
	else if (unite == ’c’)
		cout << longueur << " cm == " << longueur / conversion << " in\n";
	else
		cout << "Desole, je ne connais pas cette unité " << unite << endl;


	return 0;
}
