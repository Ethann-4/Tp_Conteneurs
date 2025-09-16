#include <iostream>
#include <typeinfo> 

using namespace std;

template <typename T>
T Maximum(T n1, T n2)
{
	return (n1 > n2) ? n1 : n2;
}

int main()
{
	using namespace std;

	cout << "Test d'une fonction de comparaison 'template' (version caracteres)" << endl;

	char c1 = ' ';
	char c2 = ' ';
	cout << "Entrez le caractere c1 : ";
	cin >> c1;
	cout << "Entrez le caractere c2 : ";
	cin >> c2;


	char resultat = Maximum(c1, c2); 

	cout << "\nLe maximum entre '" << c1 << "' et '" << c2
		<< "' est : '" << resultat << "'" << endl;

	cout << "Code ASCII de '" << resultat << "' = " << int(resultat) << endl;

	return 0;
}
