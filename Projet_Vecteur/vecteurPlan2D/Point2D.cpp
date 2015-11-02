#include <string>
#include <iostream>
#include <cmath>
#include "Point2D.h"

using namespace std;

Point2D::Point2D()
{

}

Point2D::Point2D(double x, double y, string const& nom)
{
	this->x = x;
	this->y = y;
	this->nom = nom;
}

double Point2D::getX() const
{
	return this->x;
}

double Point2D::getY() const
{
	return this->y;
}

string Point2D::getNom() const
{
	return this->nom;
}

void Point2D::setX(double x)
{
	this->x = x;
}

void Point2D::setY(double y)
{
	this->y = y;
}

void Point2D::setNom(string const& nom)
{
	this->nom = nom;
}

bool operator==(Point2D const& a,Point2D const& b)
{
	return ((a.getX() == b.getX()) && (a.getY() == b.getY()));
}

ostream& operator<<(ostream &flux, Point2D const& a)
{
	flux << a.getNom() << "(" << a.getX() << "," << a.getY() << ")";
	
	return flux;
}

double Point2D::distance(Point2D const& b) const
{
	return sqrt(pow((b.x - this->x),2.0) + pow((b.y - this->y),2.0));
}

Point2D::~Point2D()
{

}
