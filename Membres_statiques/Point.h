#pragma once
#include <iostream>
#include <cmath>   
using namespace std;

class Point {
private:
	double x, y;           
	static int nbPoints;   

public:

	Point();
	Point(double x, double y);
	~Point();

	static int compte();

	static double distance(Point& a, Point& b);
	static Point milieu(Point& a, Point& b);

	void affiche() {
		cout << "<" << x << "," << y << ">";
	}

};
