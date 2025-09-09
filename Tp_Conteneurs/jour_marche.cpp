#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Marchand
{
	string nom;
	int Emplacement;
};

bool comparer(Marchand& a, Marchand& b) {
	return a.nom < b.nom;
}

int main()
{
	int nbEmplacement;
	cin >> nbEmplacement;

	vector<Marchand> marchands;

	for (int i = 1; i <= nbEmplacement; i++) {
		string nom;
		cin >> nom;
		marchands.push_back({ nom, i });
	}

	sort(marchands.begin(), marchands.end(), comparer);

	for (Marchand& m : marchands) {
		cout << m.nom << " " << m.Emplacement << endl;
	}
}
