#include <iostream>
using namespace std;


template <typename T1, typename R>
R moyenne(T1 tableau[], int n)
{
	R  monResultat = 0;
	for (int i = 0; i < n; i++)
	{
		monResultat += tableau[i];
	}
	return  monResultat / n;
}


int main()
{
	
	int tabInt[5] = {10,20,30,40,50};
	
	float tabFloat[5] = {1.5,2.5,3.5,4.5,5.5};

	cout << "Test fonction modele 'moyenne'" << endl ;

	int m1 = moyenne<int, int>(tabInt, 5);
	cout << "Moyenne (int->int) : " << m1 << endl;


	float m2 = moyenne<int, float>(tabInt, 5);
	cout << "Moyenne (int->float) : " << m2 << endl;


	double m3 = moyenne<float, double>(tabFloat, 5);
	cout << "Moyenne (float->double) : " << m3 << endl;

	return 0;
}
