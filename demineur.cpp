/**
 * @file demineur.cpp
 * @author Tea Steven 108, Mellouk Marwan 106
 * @brief 
 * @version 1
 * @date 11/12/2021
 */

#include <iostream>
using namespace std;

#include "Grille.hpp"

int main()
{
    /* Initialise une graine aleatoire */
    srand(time(NULL));
    Grille grille;
    int saisieUtilisateur = 0;

    initialiser(grille);
    
    cin >> saisieUtilisateur;
    switch(saisieUtilisateur)
    {
        case 1:
            produireProbleme(grille);
            break;
        case 2:
            produireGrille(grille);
            break;
        case 3:
            determinerPartieGagne(grille);
            break;
        case 4:
            determinerPartiePerdu(grille);
            break;
        case 5:
            ProduireCoupParOrdi(grille);
            break;
        default:
            cout << "Erreur de saisie" << endl;
            break;
    }

    detruire(grille.historique);
    return 0;
}