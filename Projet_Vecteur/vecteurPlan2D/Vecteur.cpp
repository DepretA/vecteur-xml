#include <iostream>
#include <string>
#include "Point2D.h"
#include "Vecteur.h"

using namespace std;

Vecteur::Vecteur()
{
}

Vecteur::Vecteur(Point2D const& p1, Point2D const& p2)
{
	this->p1 = p1;
	this->p2 = p2;
	this->x = (this->p2.getX() - this->p1.getX());
	this->y = (this->p2.getY() - this->p1.getY());
}

Vecteur::Vecteur(Point2D const& p1, Point2D const& p2, double x, double y)
{
	this->p1 = p1;
	this->p2 = p2;
	this->x = x;
	this->y = y;
}

Point2D Vecteur::getP1() const
{
	return this->p1;
}

Point2D Vecteur::getP2() const
{
	return this->p2;
}

double Vecteur::getVX() const
{
	return this->x;
}

double Vecteur::getVY() const
{
	return this->y;
}

void Vecteur::setP1(Point2D const& p1)
{
	this->p1 = p1; 
	this->x = (this->p2.getX() - this->p1.getX());
	this->y = (this->p2.getY() - this->p1.getY());
}

void Vecteur::setP2(Point2D const& p2)
{
	this->p2 = p2;
	this->x = (this->p2.getX() - this->p1.getX());
	this->y = (this->p2.getY() - this->p1.getY()); 
}

double Vecteur::getDistance() const
{
	return this->p1.distance(this->p2);
}

bool Vecteur::milieu(Vecteur const& v2) const
{
	return ( (this->p2 == v2.getP1()) && (this->getDistance() == v2.getDistance()) );
}

bool Vecteur::estColineaire(Vecteur const& v2) const
{
	return ( (this->x/v2.getVX()) == (this->y/v2.getVY()) );
}

double Vecteur::facteurDeColinearite(Vecteur const& v2) const
{
	if (this->estColineaire(v2))
	{
		return (this->x/v2.getVX());
	}
	else
	{
		return 0.0;
	}
}

Vecteur::~Vecteur()
{

}

bool operator==(Vecteur const& v1, Vecteur const& v2)
{
	return ((v1.getVX() == v2.getVX()) && (v1.getVY() == v2.getVY()));
}

ostream& operator<<(ostream& flux, Vecteur const& v1)
{
	flux << v1.getP1().getNom() << v1.getP2().getNom() << "(" << v1.getVX() << "," << v1.getVY() << ")";
	
	return flux;
}

Vecteur* operator+(Vecteur const& v1, Vecteur const& v2)
{
	return new Vecteur(v1.getP1(), v2.getP2(), (v1.getVX() + v2.getVX()), (v1.getVY() + v2.getVY()));
}

