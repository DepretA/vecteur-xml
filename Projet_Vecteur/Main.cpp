#include <iostream>
#include <vector>
using namespace std;


#include "tinyXML/tinystr.h"
#include "tinyXML/tinyxml.h"
#include "vecteurPlan2D/Point2D.h"
#include "vecteurPlan2D/Vecteur.h"
#include "vecteurXML/VecteurtoXML.h"
#include "vecteurXML/XMLtoVecteur.h"


int main(int argc, char* argv[])
{
	Point2D* p1 = new Point2D(-7.0/2.0,2.0,"A");
	Point2D* p2 = new Point2D(-2.0,5.0,"B");
	Point2D* p3 = new Point2D(5.0,13.0/2.0,"C");
	Point2D* p4 = new Point2D(3.0,5.0/2.0,"D");
	Point2D* p5 = new Point2D(-23.0,1.0/2.0,"I");
	Point2D* p6 = new Point2D(-5.5/2.0,7.0/2.0,"J");
	
	if ((*p1) == (*p2))
	{
		cout << (*p1) << " et " << (*p2) << " sont égaux" << endl;
	}
	else
	{
		cout << (*p1) << " et " << (*p2) << " ne sont pas égaux" << endl;
	}

	cout << "distance entre " << (*p1) << " et " << (*p2) << " : " << p1->distance(*p2) << endl;

	Vecteur* v1 = new Vecteur(*p1,*p6);
	Vecteur* v2 = new Vecteur(*p6,*p2);
	Vecteur* v3 = new Vecteur(*p5,*p1);
	Vecteur* v4 = new Vecteur(*p5,*p4);

	cout << (*v1) << endl;
	cout << (*v2) << endl;
	cout << "distance du vecteur " << (*v1) << " : " << v1->getDistance() << endl;

	Vecteur* vm = ((*v1) + (*v2));

	if (v1->milieu(*v2))
	{
		cout << v1->getP2() << " est le milieu du vecteur " << (*vm) << endl;
	}
	else
	{
		cout << v1->getP2() << " n'est pas le milieu du vecteur " << (*vm) << endl;
	}
	
	if (v3->estColineaire(*v4))
	{
		cout << (*v3) << " = " << v3->facteurDeColinearite(*v4) << " * " << (*v4) << endl;
	}
	else
	{
		cout << (*v3) << " n'est pas colinéaire à " << (*v4) << endl;
	}

	cout << (*v1) << " = " << (*v2) << " ? " << ((*v1) == (*v2)) << endl;

	vector<Vecteur> vecteurs;
	vecteurs.push_back(*v1);
	vecteurs.push_back(*v2);
	vecteurs.push_back(*v3);
	vecteurs.push_back(*v4);
	
	VecteurtoXML vXml("vecteurXML.xml",vecteurs);

	XMLtoVecteur Xmlv("vecteurXML.xml");
	
	for (int i=0; i<Xmlv.getVecteurs().size(); i++)
	{
		cout << Xmlv.getVecteurs()[i] << endl;
	}

	delete p1;
	delete p2;

	return 0;
}
