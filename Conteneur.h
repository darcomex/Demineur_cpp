#ifndef CONTENEUR_H_INCLUDED
#define CONTENEUR_H_INCLUDED

#include <iostream>
#include <cassert>
using namespace std;

#include "ItemConteneur.hpp"

/** @brief Conteneur d'items allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension
 */ 
struct Conteneur
{
    unsigned int capacite; 	   // capacit� du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
	ItemConteneur* tab;				   // conteneur allou� en m�moire dynamique
};

void initialiser(Conteneur& t, unsigned int c, unsigned int p);
void detruire(Conteneur& t);
ItemConteneur lire(const Conteneur& t, unsigned int i); 
void ecrire(Conteneur& t, unsigned int i, const ItemConteneur& it);
ItemConteneur tirageAleatoire(Conteneur& t);

#endif /* CONTENEUR_H_INCLUDED */