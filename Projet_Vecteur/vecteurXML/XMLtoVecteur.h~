#ifndef DEF_XMLTOVECTEUR
#define DEF_XMLTOVECTEUR

#include <string>
#include <vector>
#include <iostream>
#include "../vecteurPlan2D/Vecteur.h"
#include "../vecteurPlan2D/Point2D.h"
#include "../tinyXML/tinystr.h"
#include "../tinyXML/tinyxml.h"

using namespace std;

class XMLtoVecteur
{
	
	protected:
		vector<Vecteur> vecteurs;
		
	public:
		XMLtoVecteur(string path);

		vector<Vecteur> getVecteurs();
		
		Vecteur xmlToVecteur(TiXmlElement* v);
	
		Point2D xmlToPoint(TiXmlElement* p);
		
		~XMLtoVecteur();
};

#endif
