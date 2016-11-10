#if !defined(__ECOLE_H__)
#define __ECOLE_H__

#include <iostream>
#include <string>
#include "coordonnee.h"
#include "tableau.h"
#include "personne.h"


using namespace std;

class Ecole{
  private:
	string nom;
    	Coordonnee adresse;
    	int capacite;
    	Tableau<Personne> listeEleves;
  public:
    	Ecole();
    	Ecole(int capaciteMax, string nom, Coordonnee c);
    	~Ecole();
   
    	string getNom() const;
    	Coordonnee getAdresse() const;
    	bool plaine() const;
    	int nombreInscrits();
    	int getCapacite();
    	Personne getEleve(int i);
    	bool inscrire(const Personne& p);
    	bool desinscrire(const Personne& p);
    	void afficherLesEleves(const Ecole &e)const;
    	static int distancesEcolePersonne(Tableau<Ecole> &tabEcoles,Personne &eleve);
  private:
    	friend std::ostream& operator << (std::ostream& , Ecole &);
    	friend std::istream& operator >> (std::istream& , Ecole & );
    bool operator == (const Ecole &autre )const;
	
};
#endif // ECOLE

