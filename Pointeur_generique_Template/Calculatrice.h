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

	
	T addition();
	T soustraction();
	T multiplication();
	T division();

	void afficherResultats();
};


template <class T>
T Calculatrice<T>::addition() {
	return num1 + num2;
}

template <class T>
T Calculatrice<T>::soustraction() {
	return num1 - num2;
}

template <class T>
T Calculatrice<T>::multiplication() {
	return num1 * num2;
}

template <class T>
T Calculatrice<T>::division() {
	return num1 / num2 ; 
}

template <class T>
void Calculatrice<T>::afficherResultats() {
	cout << "Le numero 1 est " << num1 << ", Le numero 2 est " << num2 << endl;
	cout << "Addition       : " << addition() << endl;
	cout << "Soustraction   : " << soustraction() << endl;
	cout << "Multiplication : " << multiplication() << endl;
	cout << "Division       : " << division() << endl;

}



