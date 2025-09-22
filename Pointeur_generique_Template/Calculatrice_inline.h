#include <iostream>
using namespace std;

template <class T>
class Calculatrice
{
private:
	T num1;
	T num2;

public:
	Calculatrice(T n1, T n2) : num1(n1), num2(n2) {}

	T addition() { return num1 + num2; }
	T soustraction() { return num1 - num2; }
	T multiplication() { return num1 * num2; }
	T division() { return num1 / num2}

	void afficherResultats() {
		cout << "Num1 = " << num1 << ", Num2 = " << num2 << endl;
		cout << "Addition       : " << addition() << endl;
		cout << "Soustraction   : " << soustraction() << endl;
		cout << "Multiplication : " << multiplication() << endl;
		cout << "Division       : " << division() << endl;
		
	}
};
