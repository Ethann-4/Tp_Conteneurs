// visite-mine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
using namespace std;

typedef enum {
	AUCUN = 0,
	GAUCHE = 1,
	DROITE = 2,
	DROIT = 3,
	HAUT = 4,
	BAS = 5
} Deplacement;


istream& operator>>(istream& is, Deplacement& d) {
	int tmp;
	if (is >> tmp)
		d = static_cast<Deplacement>(tmp);
	return is;
}

Deplacement change(Deplacement d) {
	if (d == GAUCHE) return DROITE;
	else if (d == DROITE) 
		return GAUCHE;
	else if (d == DROIT) 
		return DROIT;
	else if (d == HAUT) 
		return BAS;
	else if (d == BAS) 
		return HAUT;
	else 
		return AUCUN;
}


int main() {

	vector<Deplacement> deplacement;

	while (true) {
		Deplacement d;
		cin >> d;
		if (d == AUCUN)
			break;
		deplacement.push_back(d);
	}
		
	for (int i = deplacement.size() - 1; i >= 0; i--) {
		cout << change(deplacement[i]) << " " << endl;
	}
	
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
