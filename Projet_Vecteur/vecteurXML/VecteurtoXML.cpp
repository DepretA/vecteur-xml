#include <iostream>
#include <vector>

#include "VecteurtoXML.h"

using namespace std;

VecteurtoXML::VecteurtoXML(string path, vector<Vecteur> vecteurs) 
{
	this->path = path;
	this->vecteurs = vecteurs;

	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
	TiXmlElement* vecteursXml = new TiXmlElement("Vecteurs");

	for (int i=0; i<this->vecteurs.size(); i++)
	{
		vecteursXml->LinkEndChild(this->vecteurToXml(this->vecteurs[i]));
	}
	

	doc.LinkEndChild(decl);
	doc.LinkEndChild(vecteursXml);
	doc.SaveFile(this->path);
}


TiXmlElement* VecteurtoXML::vecteurToXml(Vecteur const& v) 
{
	TiXmlElement* vecteurXml = new TiXmlElement("Vecteur");
	vecteurXml->SetAttribute("name", (v.getP1().getNom() + v.getP2().getNom()));
	vecteurXml->SetDoubleAttribute("x", v.getVX());
	vecteurXml->SetDoubleAttribute("y", v.getVY());
	vecteurXml->LinkEndChild(this->pointToXml(v.getP1())); 
	vecteurXml->LinkEndChild(this->pointToXml(v.getP2())); 
	
	return vecteurXml;	
}

TiXmlElement* VecteurtoXML::pointToXml(Point2D const& p) 
{
	TiXmlElement* pointXml = new TiXmlElement("Point");
	TiXmlText* textPoint = new TiXmlText(p.getNom());
	pointXml->LinkEndChild(textPoint);
	pointXml->SetDoubleAttribute("x", p.getX());
	pointXml->SetDoubleAttribute("y", p.getY());

	return pointXml;
}

VecteurtoXML::~VecteurtoXML()
{

}
