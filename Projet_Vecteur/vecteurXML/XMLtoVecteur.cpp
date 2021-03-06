#include <iostream>
#include <vector>

#include "XMLtoVecteur.h"

using namespace std;

XMLtoVecteur::XMLtoVecteur(string path) 
{
	TiXmlDocument doc(path);

	bool loadOkay = doc.LoadFile();

	if (loadOkay)
	{
		TiXmlNode* vecteurs = doc.FirstChild("Vecteurs");

		if (vecteurs != NULL)
		{
			TiXmlElement* child = vecteurs->FirstChildElement();

			while (child != NULL)
			{
				this->vecteurs.push_back(this->xmlToVecteur(child));
				child = child->NextSiblingElement();			
			} 
		}
		else
		{
			cout << "Bad document " << path << endl;
		}		
	}
	else
	{
		cout << "Failed to load file " << path << endl;
	}	
}

vector<Vecteur> XMLtoVecteur::getVecteurs() 
{
	return this->vecteurs;
}

Vecteur XMLtoVecteur::xmlToVecteur(TiXmlElement* v) 
{
	Vecteur vecteur;
	
	vecteur.setP1(this->xmlToPoint(v->FirstChildElement()));
	
	vecteur.setP2(this->xmlToPoint(v->FirstChildElement()->NextSiblingElement()));

	return vecteur;	
}

Point2D XMLtoVecteur::xmlToPoint(TiXmlElement* p) 
{
	Point2D point;
	
	double x;
	if (p->QueryDoubleAttribute("x",&x) == TIXML_SUCCESS)
	{
		point.setX(x);
	}
	else
	{
		point.setX(0.0);
	}
	
	double y;
	if (p->QueryDoubleAttribute("y",&y) == TIXML_SUCCESS)
	{
		point.setY(y);
	}
	else
	{
		point.setY(0.0);
	}

	
	//cout << p->GetText() << endl;
	point.setNom(p->GetText());

	return point;
}

XMLtoVecteur::~XMLtoVecteur()
{

}
