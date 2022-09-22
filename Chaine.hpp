#ifndef CHAINE_HPP_INCLUDED
#define CHAINE_HPP_INCLUDED

/**
 * @file Chaine.h
 * @brief Projet sem06-tp-Cpp1
 * @author l'equipe pedagogique
 * @version 1 25/01/05
 * Composant de chaine d'items avec simple chainage
 * Structures de donnees et algorithmes - DUT1 Paris 5
 */

#include "Item.hpp"

/** Type Maillon avec le principe du simple chainage (maillon suivant)
 */
struct Maillon {
    Item elem;     // Element (du maillon) de la liste chainee
    Maillon* suiv; // Pointeur sur le maillon suivant
};

/** Type Chaine 
 *  Reperes du debut de chaine et du  maillon courant
 */
struct Chaine {
    Maillon* tete;     // Pointeur sur le maillon de tete
    Maillon** courant; // Superpointeur (pointeur du pointeur) 
    				   // designant le maillon courant		   		   
};

/** 
 * brief Initialisation d'une chaine vide
 * la liste est allouee en memoire dynamique
 * @see detruire, la liste est a desallouer en fin d'utilisation
 * @param[out] c : la chaine
 */
void initialiser(Chaine& c);

/** 
 * brief Desallocation d'une chaine
 * @see initialiser, la liste a deja ete allouee en memoire dynamique
 * @param[out] c : la chaine
 */
void detruire(Chaine& c);

/**
 * @brief Test de chaine vide
 * @param[in] c : la chaine testee
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c);

/**
 * @brief Insertion d'un element avant le maillon courant
 * Le nouveau maillon devient le maillon courant 
 * @param[in,out] c : la chaine
 * @param[in] elem : l'element insere
 */
void inserer(Chaine& c, const Item& elem);

/**
 * @brief Suppression du maillon courant
 * @param[in,out] c : la chaine
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaine
 */
void supprimer(Chaine& c);

/**
 * @brief Modification de l'element stocke dans le maillon courant
 * @param[in,out] c : la chaine
 * @param[in] elem : l'element a ecrire
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaine
 */
void ecrire(Chaine& c, const Item& elem);

/**
 * @brief Lecture de l'element stocke dans le maillon courant 
 * @param[in] c : la chaine
 * @return l'element lu
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaine
 */
Item lire(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en debut de chaine
 * @param[in,out] c : la chaine
 */
void debut(Chaine& c);

/**
 * @brief Test de debut de chaine
 * @param[in] c : la chaine testee
 * @return true si le maillon courant est le debut de chaine, false sinon
 */
bool estDebut(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en fin de chaine
 * @param[in,out] c : la chaine
 * @return true si le maillon courant est la fin de chaine, false sinon
 */
void fin(Chaine& c);

/**
 * @brief Test de fin de chaine
 * @param[in] c : la chaine testee
 * @return true si le maillon courant est la fin de chaine, false sinon.
 */
bool estFin(const Chaine& c);

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param[in,out] c : la chaine
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaine
 */
void suivant(Chaine& c);

#endif /* CHAINE_HPP_INCLUDED */