#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	Point p0, p1(4, 0), p2(2.5, 2.5);
	Point* pp = new Point(1, 1);

	cout << "Il y a " << Point::compte() << " points " << endl;

	delete pp;
	
	cout << "Il y a " << Point::compte() << " points " << endl;

	double distance = Point::distance(p1, p2);
	cout << "La distance entre p1 et p2 est de " << distance << endl;

	Point pointMilieu = Point::milieu(p1, p2);
	cout << "Le point milieu entre p1 et p2 est ";

	pointMilieu.affiche();
	cout << endl;



}
