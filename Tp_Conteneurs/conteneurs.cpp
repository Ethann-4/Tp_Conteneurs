#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string concatene(vector<string>& v) {
	string resultat;

	for (size_t i = 0; i < v.size(); ++i) {
		resultat += v[i];
		if (i < v.size() - 1) {
			resultat += " "; 
		}
	}

	return resultat;
}

void Affiche(vector<string>& i) {
	for (auto& mot : i) {
		cout << mot << " ";
	}
	cout << endl;
}

int main() {

	vector<string> monVecteur;

	monVecteur.push_back("bonjour");
	monVecteur.push_back("comment");
	monVecteur.push_back("allez");
	monVecteur.push_back("vous");
	monVecteur.push_back("?");

	Affiche(monVecteur);

	monVecteur.insert(monVecteur.begin() + 1, "a tous");
	

	Affiche(monVecteur);

	cout << "Taille du vecteur : " << monVecteur.size() << endl;

	cout << "Capacite du vecteur : " << monVecteur.capacity() << endl;

	monVecteur.back() = "!";
	string phrase = concatene(monVecteur);

	cout << "concatene : " << phrase << endl;



	return 0;
}
