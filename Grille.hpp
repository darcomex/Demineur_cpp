#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED

/**
 * @file Grille.hpp
 * @author Tea Steven 108, Mellouk Marwan 106
 * @brief Structure de donnees Grille
 * @version 1
 * @date 11/12/2021
 */

#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

#include "Case.hpp"
#include "Conteneur.h"
#include "ListeHistorique.hpp"

enum {LIGNES = 0, COLONNES = 1};
#define MAX_SAISIE_DEMINEUR 50

/* Grille, conteneur de Cases */
struct Grille
{
    enum {CAPACITE = 16}; // Capacite maximale de cases en lignes et colonnes
    Case cases[CAPACITE][CAPACITE]; // Grille de cases (tableau statique)
    int nbLignesColonnes[2]; // tableau a 2 valeurs, indice 0, nombre de lignes, indice 1, nombre de colonnes
    int nbMines; // Nombre de mines dans la grille
    ListeHistorique historique; // Historique de coups de la grille
};

/**
 * @brief Initialise la grille
 * @param[in,out] g : la grille
 */
void initialiser(Grille& g);

/**
 * @brief Initialise un probleme et place aleatoirement les mines
 * @param[in,out] g : la grille
 */
void initialiserProbleme(Grille& g);

/**
 * @brief Saisie les donnees d'utilisateur afin de creer un probleme
 * @param[in,out] g : la grille
 */
void saisieProbleme(Grille& g);

/**
 * @brief Genere aleatoirement des mines sur la grille
 * @param[in,out] g : la grille
 */
void genererMines(Grille& g);

/**
 * @brief Compte le nombre de mines dans toutes les cases de la grille
 * @param[in,out] g : la grille 
 */
void compterMines(Grille& g);

/**
 * @brief Recherche et affiche la position des mines
 * @param[in] g : la grille
 */
void positionMines(Grille const& g);

/**
 * @brief Affiche le probleme
 * @param[in] g : la grille 
 */
void afficherProbleme(Grille const& g);

/**
 * @brief Place une mine par l'utilisateur
 * @param[in,out] g : la grille 
 * @param[in] posMine : la position de la mine
 */
void placerMine(Grille& g, int posMine);

/**
 * @brief Affiche la grille
 * @param[in] g : la grille
 */
void afficher(Grille const& g);

/**
 * @brief Produit un historique de coup
 * @param[in] g : la grille
 */
void produireHistoriqueDeCoups(Grille const& g);

/**
 * @brief Produit un nouveau coup dans une grille
 * @param[in,out] g : la grille 
 */
void produireCoup(Grille& g);

/**
 * @brief Demasque une case dans une grille avec une position donnee
 * @param[in,out] g : la grille
 * @param[in] position : position de la case dans la grille
 */
void demasquerCase(Grille& g, int position);

/**
 * @brief Fonction recursive qui demasque les cases autour d'une case a 0 mine
 * @param[in,out] g : la grille 
 */
void demasquerCasesAutour(Grille& g, int position[2]);

/**
 * @brief Marque une case dans une grille avec une position donnee
 * @param[in-out] g : la grille
 * @param[in] position : position de la case dans la grille
 */
void marquerCase(Grille& g, int position);

/**
 * @brief Renvoie la ligne et colonne d'un element grace a une position
 * @param[in] colonnes : le nombre de colonnes dans la grille
 * @param[in] position : la position
 * @param[in,out] dansLaGrille[2] : les valeurs en ligne et colonne dans le tableau
 */
void positionDansTableau(int colonnes, int position, int dansLaGrille[2]);

/**
 * @brief Verifie et affiche si la partie est gagne
 * @param[in] g : la grille
 */
void jeuGagne(Grille const& g);

/**
 * @brief Verifie et affiche si la partie est perdu
 * @param[in] g : la grille
 */
void jeuPerdu(Grille const& g);

/**
 * @brief Verifie si le jeu est termine
 * @param[in] g : la grille 
 * @return true : si le jeu est termine
 * @return false : si le jeu n'est pas termine
 */
bool jeuFini(Grille const& g);

/**
 * @brief Recupere une grille a partir d'un tableau
 * de chaine de caracteres
 * @param[in,out] g : la grille 
 */
void extractionGrille(Grille& g, char chaine[MAX_SAISIE_DEMINEUR][MAX_SAISIE_DEMINEUR]);

/**
 * @brief Ecrit dans le conteneur les positions des cases qui n'ont pas
 * encore ete demasquee, ni marquee
 * @param[in,out] g : la grille
 * @param[in,out] c : le conteneur
 */
void recupererCasesNonDemasquee(Grille& g, Conteneur& c);

/**
 * @brief Premiere commande qui permet de produire un probleme
 * avec un nombre de lignes, colonnes et mines
 * @param[in,out] g : la grille utilisee
 */
void produireProbleme(Grille& g);

/**
 * @brief Deuxieme commande produit une grille avec un probleme
 * et un historique de coups
 * @param[in,out] g : la grille utilisee
 */
void produireGrille(Grille &g);

/**
 * @brief Troisieme commande determiner si la partie est gagnee
 * a partir d'un probleme et d'un historique de coups
 * @param[in,out] g : la grille utilisee
 */
void determinerPartieGagne(Grille& g);

/**
 * @brief Quatrieme commande determiner si la partie est perdue
 * a partir d'un probleme et d'un historique de coups
 * @param[in,out] g : la grille utilisee
 */
void determinerPartiePerdu(Grille& g);

/**
 * @brief Cinquieme commande produire un nouveau coup a partir
 * d'une grille
 * @param[in,out] g : la grille
 */
void ProduireCoupParOrdi(Grille& g);

#endif /* GRILLE_HPP_INCLUDED */