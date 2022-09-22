/**
 * @file ListeHistorique.cpp
 * Projet sem06-tp-Cpp3
 * @author l'equipe pedagogique 
 * @version 1 - 26/01/06
 * @brief Composant de ListeHistorique d'items stockes dans une chaine a simple chainage
 * Structures de donnees et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "ListeHistorique.hpp"

/**
 * @brief Initialiser une liste vide
 * la ListeHistorique est allouee en memoire dynamique
 * @see detruire, elle est a desallouer en fin d'utilisation
 * @param[out] l : la liste a initialiser (vide)  
 */
void initialiser(ListeHistorique& l)
{
	initialiser(l.ch);
	l.nb = 0;
	l.index = 0;
}

/**
 * @brief Desallouer une liste
 * @see initialiser, la ListeHistorique a deja ete allouee en memoire dynamique
 * @param[out] l : la ListeHistorique
 */
void detruire(ListeHistorique& l)
{
	detruire(l.ch);
}
	
/**
 * @brief Longueur de ListeHistorique
 * @param[in] l : la ListeHistorique
 * @return la longueur
 */
unsigned int longueur(const ListeHistorique& l)
{
	return l.nb;
}

/**
 * @brief Deplacer la position courante a une position donnee dans la ListeHistorique
 * @param[in,out] l : la ListeHistorique
 * @param[in] i : la position de deplacement
 * @pre 0<=i<=longueur(l)
 * La fonction ci-dessous n'est pas presente dans le fichier d'entete. 
 * C'est une fonction utilitaire qui n'a pas vocation a etre employee par les 
 * utilisateurs du type ListeHistorique. C'est pourquoi elle est declaree 'static'.
 */
static void deplacer(ListeHistorique& l, unsigned int i)
{
	assert(0 <= i && i <= l.nb);
	l.index = i;
	debut(l.ch);
	for(int j = 0; j < i; j++)
	{
		suivant(l.ch);
	}
}

/**
 * @brief Lire un element de ListeHistorique
 * @param[in] l : la ListeHistorique
 * @return l'item lu
 * @pre 0<=i<longueur(l)
 */
Item lire(ListeHistorique& l, unsigned int i)
{
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	return (lire(l.ch));
}

/**
 * @brief Ecrire un item dans la ListeHistorique
 * @param[in,out] l : la ListeHistorique
 * @param[in] i : position de l'element a ecrire
 * @param[in] it : l'item
 * @pre 0<=i<longueur(l)
 */
void ecrire(ListeHistorique& l, unsigned int i, const Item& it)
{
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	ecrire(l.ch, it);
}

/**
 * @brief Inserer un element dans une ListeHistorique
 * @param[in,out] l : la ListeHistorique
 * @param[in] i : la position avant laquelle l'element est insere
 * @param[in] it : l'element insere
 * @pre 0<=i<=longueur(l)
 */
void inserer(ListeHistorique& l, unsigned int i, const Item& it)
{
	assert((i >= 0) && (i <= longueur(l)));
	deplacer(l, i);
	inserer(l.ch, it);
	l.nb++;
}
	
/**
 * @brief Supprimer un element dans une ListeHistorique
 * @param[in,out] l : la ListeHistorique
 * @param[in] i : la position de l'element a supprimer
 * @pre 0<=i<longueur(l)
 */
void supprimer(ListeHistorique& l, unsigned int i) 
{
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	supprimer(l.ch);
	l.nb--;
}