/**
 * @file Case.hpp
 * @author Tea Steven 108, Mellouk Marwan 106
 * @brief Structure de donnees Case
 * @version 1
 * @date 11/12/2021
 */

#ifndef CASE_HPP_INCLUDED
#define CASE_HPP_INCLUDED

/* Case dans la grille */
struct Case
{
    int nbMines; // Indique le nombre de mines autour d'une case
    bool estMine; // Est une mine ou non
    bool estDesmasquee; // Est demasquee ou non
    bool estMarquee; // Est marquee ou non
};

#endif /* CASE_HPP_INCLUDED */