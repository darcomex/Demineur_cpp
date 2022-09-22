#ifndef LISTEHISTORIQUE_HPP_INCLUDED
#define LISTEHISTORIQUE_HPP_INCLUDED

/**
 * @file ListeHistorique.cpp
 * Projet sem06-tp-Cpp3
 * @author l'equipe pedagogique 
 * @version 1 - 26/01/06
 * @brief Composant de ListeHistorique d'items stockes dans une chaine a simple chainage
 * Structures de donnees et algorithmes - DUT1 Paris 5
 */
 
#include "Chaine.hpp"

/** 
 * Liste geree dans une chaine d'items 
 */
struct ListeHistorique 
{
    Chaine ch;	// Stockage des elements de liste dans une chaine d'items
	unsigned int nb;    // nombre d'elements dans la liste
	unsigned int index;	// index de la position courante dans la chaine    
};

/**
 * @brief Initialiser une liste vide
 * la ListeHistorique est allouee en memoire dynamique
 * @see detruire, elle est a desallouer en fin d'utilisation
 * @param[out] l : la liste a initialiser (vide)  
 */
void initialiser(ListeHistorique& l);

/**
 * @brief Desallouer une liste
 * @see initialiser, la ListeHistorique a deja ete allouee en memoire dynamique
 * @param[out] l : la ListeHistorique
 */
void detruire(ListeHistorique& l);

/**
 * @brief Longueur de ListeHistorique
 * @param[in] l : la ListeHistorique
 * @return la longueur
 */
unsigned int longueur(const ListeHistorique& l);

/**
 * @brief Lire un element de ListeHistorique
 * @param[in] l : la ListeHistorique
 * @return l'item lu
 * @pre 0<=i<longueur(l)
 */
Item lire(ListeHistorique& l, unsigned int i);

/**
 * @brief Ecrire un item dans la ListeHistorique
 * @param[in,out] l : la ListeHistorique
 * @param[in] i : position de l'element a ecrire
 * @param[in] it : l'item
 * @pre 0<=i<longueur(l)
 */
void ecrire(ListeHistorique& l, unsigned int i, const Item& it);

/**
 * @brief Inserer un element dans une ListeHistorique
 * @param[in,out] l : la ListeHistorique
 * @param[in] i : la position avant laquelle l'element est insere
 * @param[in] it : l'element insere
 * @pre 0<=i<=longueur(l)
 */
void inserer(ListeHistorique& l, unsigned int i, const Item& it);

/**
 * @brief Supprimer un element dans une ListeHistorique
 * @param[in,out] l : la ListeHistorique
 * @param[in] i : la position de l'element a supprimer
 * @pre 0<=i<longueur(l)
 */
void supprimer(ListeHistorique& l, unsigned int i);

#endif /* LISTEHISTORIQUE_HPP_INCLUDED */
