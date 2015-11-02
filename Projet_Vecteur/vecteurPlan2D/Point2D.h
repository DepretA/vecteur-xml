#ifndef DEF_POINT2D
#define DEF_POINT2D

#include <string>
#include <iostream>

using namespace std;

class Point2D
{

	protected:
		double x;
		double y;
		string nom;
	
	public:
		Point2D();
		Point2D(double x, double y, string const& nom);

		double getX() const;
		double getY() const;
		string getNom() const;

		void setX(double x);
		void setY(double y);
		void setNom(string const& nom);

		double distance(Point2D const& b) const;

		~Point2D();

};

bool operator==(Point2D const& a, Point2D const& b);
ostream& operator<<(ostream &flux, Point2D const& a);

#endif
