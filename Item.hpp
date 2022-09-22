#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

/**
 * @file Item.h
 * @author l'equipe pedagogique 
 * @version 1 23/12/05
 * @brief Specialisation du type Item
 * Structures de donnees et algorithmes - DUT1 Paris 5
 */

#include <iostream>
using namespace std;

struct ChaineCharacteres
{
    enum {CAPACITE = 5};
    char chaine[CAPACITE];
};

typedef ChaineCharacteres Item;

#endif /* ITEM_HPP_INCLUDED */