#ifndef DEF_VECTEUR
#define DEF_VECTEUR

#include <string>
#include <iostream>
#include "Point2D.h"

using namespace std;

class Vecteur
{
	
	protected:
		Point2D p1;
		Point2D p2;
		double x;
		double y;
		
	public:
		Vecteur();
		Vecteur(Point2D const& p1, Point2D const& p2);
		Vecteur(Point2D const& p1, Point2D const& p2, double x, double y);
		
		Point2D getP1() const;
		Point2D getP2() const;
		double getVX() const;
		double getVY() const;		
		
		void setP1(Point2D const& p1);
		void setP2(Point2D const& p2);
		
		double getDistance() const;
		bool milieu(Vecteur const& v2) const;
		bool estColineaire(Vecteur const& v2) const;
		double facteurDeColinearite(Vecteur const& v2) const;
		
		~Vecteur();
};

bool operator==(Vecteur const& v1, Vecteur const& v2);
ostream& operator<<(ostream& flux, Vecteur const& v1);
Vecteur* operator+(Vecteur const& v1, Vecteur const& v2);

#endif
		
		
