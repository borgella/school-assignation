/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Été 2015 / TP1                                             *
 *    AUTEUR(S): BORGELLA JEAN MARY : BORJ15048201               */

#include <algorithm>
#include <string.h>
#include "personne.h"

Personne::Personne(){
   nom = "";
   prenom = "";
}

Personne::~Personne(){}

string Personne::getNom() const{
	string nom = this->nom;
    return nom ;
}

string Personne::getPrenom(const Personne& autre) const{
    string prenom = autre.prenom;
    return prenom;
}
Coordonnee Personne::getAdresse() const
{
    Coordonnee coor = this->adresse;
    return coor;
}

bool Personne::operator ==(const Personne &autre) const
{
    if(this == &autre) return true;
	if(!(this->nom.compare(autre.nom) && this->prenom.compare(autre.prenom)) && this->adresse == autre.adresse)
		return true;
    return false;
}

std::istream& operator >>(std::istream& is, Personne& p){
    string nom;
    string prenom;
    Coordonnee coor;
    char c;
    is >> nom;
    is >> prenom;
    if(nom.empty() || prenom.empty() || is.eof()) return is;
    is >> coor >> c;
        assert(c==';');
		p.nom = nom;
		p.prenom = prenom;
		p.adresse = coor;	
    return is;
}

std::ostream& operator << (std::ostream &os, const Personne &p)
{
    os << p.nom 
	   <<" "
	   << p.prenom
	   <<"\n" ;
   return os;
}


