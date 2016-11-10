/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Été 2015 / TP1                                             *
 *    AUTEUR(S): BORGELLA JEAN MARY + BORJ15048201               */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "tableau.h"
#include "personne.h"
#include "ecole.h"

using namespace std;
void 
afficherLaListeDEcoles(Tableau<Ecole> &tab);

int main(int argc, const char** argv)
{
    	Tableau<Personne> tableauEleves;
    	Tableau<Ecole> tableauEcoles;
    	ifstream fichierEleves(argv[1]);
	
	while(fichierEleves){
            Personne nouvellePersonne;
            fichierEleves >> nouvellePersonne;
            if(fichierEleves.eof()) break;
            tableauEleves.ajouter(nouvellePersonne);	
    	}
    	ifstream fichierEcoles(argv[2]);
    	while(fichierEcoles){
            Ecole nouvelleEcole;
            fichierEcoles >> nouvelleEcole;
            if(fichierEcoles.eof()) break;
            tableauEcoles.ajouter(nouvelleEcole);	
    	}
	for(int i = 0 ; i<tableauEleves.taille(); ++i){	
		int ecoleProche = Ecole::distancesEcolePersonne(tableauEcoles,tableauEleves[i]);
		tableauEcoles[ecoleProche].inscrire(tableauEleves[i]);
	}
	afficherLaListeDEcoles(tableauEcoles);
    	return 0; // fin normale
}



void 
afficherLaListeDEcoles(Tableau<Ecole> &tab){
	for(int i = 0 ; i < tab.taille(); i ++){
		cout<< tab[i] << endl;
		tab[i].afficherLesEleves(tab[i]);
	}	
}

	