#ifndef DEF_VECTEURTOXML
#define DEF_VECTEURTOXML

#include <string>
#include <vector>
#include <iostream>
#include "../vecteurPlan2D/Vecteur.h"
#include "../vecteurPlan2D/Point2D.h"
#include "../tinyXML/tinystr.h"
#include "../tinyXML/tinyxml.h"

using namespace std;

class VecteurtoXML
{
	
	protected:
		string path;
		vector<Vecteur> vecteurs;
		
	public:
		VecteurtoXML(string path, vector<Vecteur> v);
		
		TiXmlElement* vecteurToXml(Vecteur const& v);
	
		TiXmlElement* pointToXml(Point2D const& p);
		
		~VecteurtoXML();
};

#endif
