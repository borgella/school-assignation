/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Été 2015 / TP1                                             *
 *    AUTEUR(S): ÉCRIVEZ ICI VOTRE NOM + CODE PERMANENT          */

#if !defined(__PERSONNE_H__)
#define __PERSONNE_H__

#include <iostream>
#include <string>
#include "coordonnee.h"
#include "tableau.h"


using namespace std;

class Personne{
  private:
    	string nom;
	string prenom;
    	Coordonnee adresse;
	
  public:
	Personne();
	~Personne();  
    	string getNom() const;
    	string getPrenom(const Personne& autre) const;
    	Coordonnee getAdresse() const;
    	bool   operator == (const Personne& autre) const;
  private: 
    	friend std::istream& operator >>(std::istream&, Personne&);
   	friend std::ostream& operator << (std::ostream &os, const Personne &p);
};

#endif
