#ifndef HISTORIQUEDECOUPS_HPP_INCLUDED
#define HISTORIQUEDECOUPS_HPP_INCLUDED

#include <iostream>
using namespace std;

struct HistoriqueDeCoups
{
    enum {CAPACITE = 100};
    string historique[CAPACITE]; // Tableau de chaine de caracteres (tableau statique)
    int nbCoups; // Nombre de coups dans l'historique
};

/**
 * @brief Ajoute un coup dans l'historique
 * @param[in-out] h : l'historique de coups
 * @param[in] coup : le coup a ajouter
 */
void ajouter(HistoriqueDeCoups& h, string coup);

/**
 * @brief Initialise l'historique de coups
 * @param[in-out] h : l'historique de coups
 */
void initialiser(HistoriqueDeCoups& h);

#endif