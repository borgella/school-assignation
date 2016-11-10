/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique

  Squelette pour classe générique Tableau<T> pour le Lab3 et TP1.
*/

// Ces deux lignes permettent d'éviter d'inclure 2 fois ce .h à la compilation.
#if !defined(__TABLEAU_H__)
 #define __TABLEAU_H__


template <class T>
class Tableau
{
  private:
  	T*             elements;
  	int            capacite;
 	int            nbElements;
  public:
    Tableau(int capacite_initiale=8);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;
    // Insère element à position index. Les éléments à partir de index sont décalés d'une position au préalable.
    void           inserer(const T& element, int index=0);
    // Enlève l'element à position index. Les éléments après index sont décalés d'une position après.
    void           enlever(int index=0);
    // Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    // Voir la méthode "trouver" dans les notes de cours. Il suffit de l'adapter pour retourner la position au lieu d'un booléen
    int            trouver(const T& element);
	
    int	     getCapacite()const;	

    T&             operator[] (int index);
    
    const T&       operator[] (int index) const;

    Tableau<T>&    operator = (const Tableau<T>& autre);

    bool           operator == (const Tableau<T>& autre) const;

  private:
    T* 	     agrandirTableau(T *tab,int capaciteDouble);
};


/*
 Puisque Tableau<T> est une classe générique, toutes ses définitions doivent être
 inclues après les déclarations. On peut quand même séparer les déclarations et
 les définitions en deux fichiers (tableau.h et tableau.hcc), à condition d'inclure le
 deuxième (tableau.hcc) à la fin du premier (tableau.h). Ainsi, un fichier source
 (.cc, .cpp, c++) qui inclut tableau.h inclura indirectement aussi tableau.hcc.

*/

//#include "tableau.hcc"
/**** Début des définitions pouvant être mises dans tableau.hcc. ****/
#include <assert.h>


template <class T>
Tableau<T>::Tableau(int capacite_initiale)
{
    capacite = capacite_initiale;
    nbElements = 0;
    elements = new T[capacite];
}


template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    capacite = autre.capacite; // ???
    nbElements = autre.nbElements;
    elements = new T[capacite];
    for(int i=0; i < nbElements; i++)
        elements[i] = autre.elements[i];
}

template <class T>
Tableau<T>::~Tableau()
{
    delete[] elements;
    elements = NULL;
}

template <class T>
int Tableau<T>::taille()const
{
    return nbElements;
}


template <class T>
void Tableau<T>::ajouter(const T& item)
{
    if(nbElements == capacite){
        elements = agrandirTableau(elements,capacite*2);
    }
    elements[nbElements++] = item;

}

// Insère element à position index. Les éléments à partir de index sont décalés d'une position vers la droite au préalable.
template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
	assert(index <= nbElements && index >= 0);
    if(nbElements == capacite)
        elements = agrandirTableau(elements,capacite*2);
    for(int i = nbElements; i > index; i--)
        elements[i] = elements[i-1];
	elements[index] = element;
    nbElements++;
}
// Enlève l'element à position index. Les éléments après index sont décalés d'une position vers la gauche.
template <class T>
void Tableau<T>::enlever(int index)
{
    assert(index < nbElements && index >= 0);
    for(int i = index; i < nbElements-1; i++)
        elements[i] = elements[i+1];
    nbElements--;
}

// Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
template <class T>
int Tableau<T>::trouver(const T& element)
{
    for(int i=0; i<nbElements; i++)
		if(elements[i] == element)
			return i;
    return -1;
}

template<class T>
int Tableau<T>::getCapacite()const{
	return capacite;
}


template <class T>
void Tableau<T>::vider()
{
    nbElements = 0;
}


template <class T>
T& Tableau<T>::operator[] (int index)
{
    assert(index < nbElements);
    return elements[index];
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    assert(index < nbElements);
    return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    if(this == &autre)
        return *this;
    nbElements = autre.nbElements;
    if(capacite < autre.nbElements){
        delete[] elements;
        capacite = autre.nbElements;
        elements = new T[capacite];
    }
    for(int i=0; i < nbElements; i++)
        elements[i] = autre.elements[i];
    return *this; // retourne le contenu du pointeur courant *this.
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
	// ici on compare les adresses memoires : prete attention a la syntaxe
    if(this == &autre)
        return true;
    if(nbElements != autre.nbElements)
        return false;
    for(int i=0; i < nbElements; i++)
        if(elements[i] != autre.elements[i])
            return false;
    return true;
}

template <class T>
T* Tableau<T>::agrandirTableau(T *tab,int capaciteDouble){
		capacite = capaciteDouble;
		T *temp = new T[capacite];
	for(int i = 0 ; i < nbElements ; i++)
			temp[i] = elements[i];
	delete[] elements;
	
	return temp;
}

#endif

