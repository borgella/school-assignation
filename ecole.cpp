#include <algorithm>
#include "ecole.h"
#include <iostream>
#include <limits>

Ecole::Ecole(){}

Ecole::Ecole(int capaciteMax, string nom, Coordonnee c)
	: listeEleves()
{
	capacite = capaciteMax;
	this->nom = nom;
	adresse = c;
}

Ecole::~Ecole(){}

string Ecole::getNom() const
{
    return nom;
}

Coordonnee Ecole::getAdresse() const
{
	return adresse;
}

bool Ecole::plaine() const
{
    return capacite == listeEleves.taille();
}

int Ecole::nombreInscrits()
{
    return listeEleves.taille();
}

int Ecole::getCapacite()
{
    return capacite;
}

Personne Ecole::getEleve(int i)
{
    return listeEleves[i];
}
//Inscription réussie => retourner vrai, sinon - faux
bool Ecole::inscrire(const Personne &p)
{
	if(plaine())
		return false;
	listeEleves.ajouter(p);
	return true;
}
//Désinscription réussie => retourner vrai, sinon - faux
bool Ecole::desinscrire(const Personne &p)
{
	int i = listeEleves.trouver(p);
	if(i < 0)
		return false;
	listeEleves.enlever(i);
    return true;
}

std::istream& operator >> (std::istream& is, Ecole& ecole)
{
    string nom;
    int capacite;
    Coordonnee coor;
    is >> nom>> capacite;
    if(nom.empty() || is.eof()) return is;
    is >> coor;
	ecole.nom = nom;
	ecole.capacite = capacite;
	ecole.adresse = coor;
    return is;
}
std::ostream& operator << (std::ostream& os, Ecole& e)
{
    os	<< "Ecole: " 
		<< e.nom 
		<< ", Adresse: " 
		<< e.adresse
	    << "\n"
		<< "Capacite: "
		<< e.capacite 
		<< " Nombre d'eleves:" 
		<< e.listeEleves.taille();
    return os;
}

bool Ecole::operator == (const Ecole &autre )const{
	if(this == &autre)return true;
	if(nom.compare(autre.nom)!= 0 || capacite != autre.capacite || !(adresse == autre.adresse))
		return false;
	for(int i = 0 ; i < listeEleves.taille();++i){
		if(!(listeEleves[i]== autre.listeEleves[i]))
			return false;
	}
	return true;
}

void Ecole::afficherLesEleves(const Ecole &e)const{
	if(e.listeEleves.taille() > 0){
		cout<<"Liste d'eleves:"<<endl;
		for(int i = 0 ; i < e.listeEleves.taille(); i ++)
			cout << e.listeEleves[i].getPrenom(e.listeEleves[i]) << " " 
			<<  e.listeEleves[i].getNom() << endl;
	}
}

int Ecole::distancesEcolePersonne(Tableau<Ecole> &tabEcoles,Personne &eleve){
	int retour = 0;
	Coordonnee coorEcole ;
	double distance, distanceMinimum = std::numeric_limits<double>::infinity();
	for(int i = 0; i < tabEcoles.taille() ;++i){
		coorEcole = tabEcoles[i].getAdresse();
		distance = coorEcole.distance(eleve.getAdresse());
		if(distance < distanceMinimum){
			if(!tabEcoles[i].plaine()){
				distanceMinimum = distance;
				retour = i;
			}
		}	
	}
	return retour;
}

