/**
 * @file Grille.cpp
 * @author Tea Steven 108, Mellouk Marwan 106
 * @brief Structure de donnees Grille
 * @version 1
 * @date 11/12/2021
 */

#include "Grille.hpp"

/**
 * @brief Fonction statique destinee a ne pas etre utilisee
 * par l'utilisateur
 * @param caractere : le caractere a verifie
 * @return true : si le caractere est un chiffre
 * @return false : si le caractere n'est pas un chiffre
 */
static bool estChiffre(char caractere)
{
    return caractere == '0' || caractere == '1' || caractere == '2' || caractere == '3' || 
    caractere == '4' || caractere == '5' || caractere == '6' || caractere == '7' || 
    caractere == '8' || caractere == '9';
}

/**
 * @brief Initialise la grille
 * @param[in,out] g : la grille
 */
void initialiser(Grille& g)
{
    initialiser(g.historique);
    g.nbLignesColonnes[LIGNES] = 0, g.nbLignesColonnes[COLONNES] = 0;
    g.nbMines = 0;
    for(unsigned int i = 0; i < Grille::CAPACITE; i++)
    {
        for(unsigned int j  = 0; j < Grille::CAPACITE; j++)
        {
            g.cases[i][j].estMarquee = false;
            g.cases[i][j].estDesmasquee = false;
            g.cases[i][j].estMine = false;
            g.cases[i][j].nbMines = 0;
        }
    }
}

/**
 * @brief Initialise un probleme et place aleatoirement les mines
 * @param[in,out] g : la grille
 */
void initialiserProbleme(Grille& g)
{
    int lignes = 0, colonnes = 0, nbMines = 0;
    cin >> lignes >> colonnes >> nbMines;
    /* Empeche de mettre plus de lignes et de colonnes que la
    capacite, et de placer plus de mines que de nombre de cases */
    assert(lignes < Grille::CAPACITE && colonnes < Grille::CAPACITE && nbMines <= lignes * colonnes);
    g.nbLignesColonnes[LIGNES] = lignes;
    g.nbLignesColonnes[COLONNES] = colonnes;
    g.nbMines = nbMines;
}

/**
 * @brief Saisie les donnees d'utilisateur afin de creer un probleme
 * @param[in,out] g : la grille
 */
void saisieProbleme(Grille& g)
{
    initialiserProbleme(g);
    int nbElemHistorique = 0;
    int posMine;
    string coup;

    for(unsigned int i = 0; i < g.nbMines; i++)
    {
        cin >> posMine;
        placerMine(g, posMine);
    }
    compterMines(g);

    cin >> nbElemHistorique;
    for(unsigned int i = 0; i < nbElemHistorique; i++)
    {
        produireCoup(g);
    }
}

/**
 * @brief Genere aleatoirement des mines sur la grille
 * @param[in,out] g : la grille
 */
void genererMines(Grille& g)
{
    Case c;
    c.estMine = true;
    c.estDesmasquee = false;
    c.nbMines = 0;
    bool tab[g.nbLignesColonnes[LIGNES]][g.nbLignesColonnes[COLONNES]] = {};
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES]; i++)
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++) 
            tab[i][j] = false;

    int position[2] = {rand() % g.nbLignesColonnes[LIGNES], rand() % g.nbLignesColonnes[COLONNES]};
    for(unsigned int i = 0; i < g.nbMines; i++)
    {
        /*
         * Regenere une nouvelle position si la case est deja
         * une mine
         */
        while(g.cases[position[LIGNES]][position[COLONNES]].estMine)
        {
            position[LIGNES] = rand() % g.nbLignesColonnes[LIGNES];
            position[COLONNES] = rand() % g.nbLignesColonnes[COLONNES];
        }
        g.cases[position[LIGNES]][position[COLONNES]] = c;
    }
}

/**
 * @brief Compte le nombre de mines dans toutes les cases de la grille
 * @param[in,out] g : la grille 
 */
void compterMines(Grille& g)
{
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES]; i++)
    {
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++)
        {
            if(i != 0 && j != 0)
            {
                if(g.cases[i-1][j-1].estMine)
                    g.cases[i][j].nbMines += 1;
            }
            if(i != 0)
            {
                if(g.cases[i-1][j].estMine)
                    g.cases[i][j].nbMines += 1;
            }
            if(i != 0 && j != g.nbLignesColonnes[COLONNES] - 1)
            {
                if(g.cases[i-1][j+1].estMine)
                    g.cases[i][j].nbMines += 1;
            }
            if(j != 0)
            {
                if(g.cases[i][j-1].estMine)
                    g.cases[i][j].nbMines += 1;
            }
            if(j != g.nbLignesColonnes[COLONNES] - 1)
            {
                if(g.cases[i][j+1].estMine)
                    g.cases[i][j].nbMines += 1;
            }
            if(i != g.nbLignesColonnes[LIGNES] - 1 && j != 0)
            {
                if(g.cases[i+1][j-1].estMine)
                    g.cases[i][j].nbMines += 1;
            }
            if(i != g.nbLignesColonnes[LIGNES] - 1)
            {
                if(g.cases[i+1][j].estMine)
                    g.cases[i][j].nbMines += 1;
            }
            if(i != g.nbLignesColonnes[LIGNES] - 1 && j != g.nbLignesColonnes[COLONNES])
            {
                if(g.cases[i+1][j+1].estMine)
                    g.cases[i][j].nbMines += 1;
            }
        }
    }
}

/**
 * @brief Recherche et affiche la position des mines
 * @param[in] g : la grille
 */
void positionMines(Grille const& g)
{
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES]; i++)
    {
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++)
        {
            if(g.cases[i][j].estMine)
                cout << i * g.nbLignesColonnes[COLONNES] + j << " ";
        }
    }
}

/**
 * @brief Affiche le probleme
 * @param[in] g : la grille 
 */
void afficherProbleme(Grille const& g)
{
    cout << g.nbLignesColonnes[LIGNES] << " " << g.nbLignesColonnes[COLONNES] << " "
    << g.nbMines << " ";
    positionMines(g);
}

/**
 * @brief Place une mine par l'utilisateur
 * @param[in,out] g : la grille 
 * @param[in] posMine : la position de la mine
 */
void placerMine(Grille& g, int posMine)
{
    int posMineDansTableau[2] = {0, 0};
    positionDansTableau(g.nbLignesColonnes[COLONNES], posMine, posMineDansTableau);
    g.cases[posMineDansTableau[LIGNES]][posMineDansTableau[COLONNES]].estMine = true;
}

/**
 * @brief Affiche la grille
 * @param[in] g : la grille
 */
void afficher(Grille const& g)
{
    int temp = -1;
    bool afficherMines = jeuFini(g);

    cout << g.nbLignesColonnes[LIGNES] << " " << g.nbLignesColonnes[COLONNES] << endl;
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES] * 2 + 1; i++)
    {
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++)
        {
            if(i % 2 == 0)
                cout << " ___";
            else
            {
                cout << "| ";
                if(g.cases[temp][j].estMine && afficherMines)
                    cout << "m";
                else
                {
                    if(g.cases[temp][j].estMarquee)
                        cout << "x";
                    else if(!g.cases[temp][j].estDesmasquee)
                        cout << ".";
                    else if(g.cases[temp][j].estDesmasquee)
                    {
                        if(g.cases[temp][j].nbMines != 0)
                            cout << g.cases[temp][j].nbMines;
                        else 
                            cout << " ";
                    }
                }
                cout << " ";
                if(j == g.nbLignesColonnes[COLONNES]-1)
                    cout << "|";
            }
        }
        if(i % 2 == 0) 
            temp++;
        cout << endl;
    }
}

/**
 * @brief Produit un nouveau coup dans une grille
 * @param[in,out] g : la grille 
 */
void produireCoup(Grille& g)
{
    Item coup;
    cin >> coup.chaine;
    assert(coup.chaine[0] == 'D' || coup.chaine[0] == 'd' || coup.chaine[0] == 'M' || coup.chaine[0] == 'm');
    
    string str_position = "";
    int position = 0;
    for(unsigned int i = 1; i < Item::CAPACITE; i++)
        str_position = str_position + coup.chaine[i];
    /* stoi permet de convertir de string a int */
    position = stoi(str_position);
    assert(position >= 0 && position <= g.nbLignesColonnes[LIGNES] * g.nbLignesColonnes[COLONNES]);

    inserer(g.historique, g.historique.nb, coup);
    if(coup.chaine[0] == 'D' || coup.chaine[0] == 'd')
    {
        demasquerCase(g, position);
        int tabPosition[2];
        positionDansTableau(g.nbLignesColonnes[COLONNES], position, tabPosition);
        if(g.cases[tabPosition[LIGNES]][tabPosition[COLONNES]].nbMines == 0)
            demasquerCasesAutour(g, tabPosition);
    }
    else
        marquerCase(g, position);
}

/**
 * @brief Demasque une case dans une grille avec une position donnee
 * @param[in,out] g : la grille
 * @param[in] position : position de la case dans la grille
 */
void demasquerCase(Grille& g, int position)
{
    int dansLaGrille[2] = {0, 0};
    positionDansTableau(g.nbLignesColonnes[COLONNES], position, dansLaGrille);
    //assert(!g.cases[dansLaGrille[LIGNES]][dansLaGrille[COLONNES]].estDesmasquee);

    g.cases[dansLaGrille[LIGNES]][dansLaGrille[COLONNES]].estDesmasquee = true;
}

/**
 * @brief Fonction recursive qui demasque les cases autour d'une case a 0 mine
 * @param[in,out] g : la grille 
 */
void demasquerCasesAutour(Grille& g, int position[2])
{
    g.cases[position[LIGNES]][position[COLONNES]].estDesmasquee = true;
    if(g.cases[position[LIGNES]][position[COLONNES]].nbMines != 0)
        return;
    else
    {
        int nouvellePos[2] = {position[LIGNES] - 1, position[COLONNES]};
        if(!g.cases[nouvellePos[LIGNES]][nouvellePos[COLONNES]].estDesmasquee && nouvellePos[LIGNES] >= 0)
            demasquerCasesAutour(g, nouvellePos);

        nouvellePos[LIGNES] = position[LIGNES] + 1;
        nouvellePos[COLONNES] = position[COLONNES];
        if(!g.cases[nouvellePos[LIGNES]][nouvellePos[COLONNES]].estDesmasquee && nouvellePos[LIGNES] < g.nbLignesColonnes[LIGNES])
            demasquerCasesAutour(g, nouvellePos);

        nouvellePos[LIGNES] = position[LIGNES];
        nouvellePos[COLONNES] = position[COLONNES] - 1;
        if(!g.cases[nouvellePos[LIGNES]][nouvellePos[COLONNES]].estDesmasquee && nouvellePos[COLONNES] >= 0)
            demasquerCasesAutour(g, nouvellePos);

        nouvellePos[LIGNES] = position[LIGNES];
        nouvellePos[COLONNES] = position[COLONNES] + 1;
        if(!g.cases[nouvellePos[LIGNES]][nouvellePos[COLONNES]].estDesmasquee && nouvellePos[COLONNES] < g.nbLignesColonnes[COLONNES])
            demasquerCasesAutour(g, nouvellePos);
    }
}

/**
 * @brief Marque une case dans une grille avec une position donnee
 * @param[in-out] g : la grille
 * @param[in] position : position de la case dans la grille
 */
void marquerCase(Grille& g, int position)
{
    int dansLaGrille[2] = {0, 0};
    positionDansTableau(g.nbLignesColonnes[COLONNES], position, dansLaGrille);
    /*assert(!g.cases[dansLaGrille[LIGNES]][dansLaGrille[COLONNES]].estDesmasquee
    && !g.cases[dansLaGrille[LIGNES]][dansLaGrille[COLONNES]].estMarquee);*/

    g.cases[dansLaGrille[LIGNES]][dansLaGrille[COLONNES]].estMarquee = true;
}

/**
 * @brief Renvoie la ligne et colonne d'un element grace a une position
 * @param[in] colonnes : le nombre de colonnes dans la grille
 * @param[in] position : la position
 * @param[in,out] dansLaGrille[2] : les valeurs en ligne et colonne dans le tableau
 */
void positionDansTableau(int colonnes, int position, int dansLaGrille[2])
{
    dansLaGrille[0] = position / colonnes;
    dansLaGrille[1] = position % colonnes;
}

/**
 * @brief Verifie et affiche si la partie est gagne
 * @param[in] g : la grille
 */
void jeuGagne(Grille const& g)
{
    bool gagne = true;
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES]; i++)
    {
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++)
        {
            if(!g.cases[i][j].estDesmasquee && !g.cases[i][j].estMine)
                gagne = false;
            if(g.cases[i][j].estDesmasquee && g.cases[i][j].estMine)
                gagne = false;
            if(g.cases[i][j].estMarquee && !g.cases[i][j].estMine)
                gagne = false;
        }
    }

    if(gagne)
        cout << "game won" << endl;
    else
        cout << "game not won" << endl;
}

/**
 * @brief Verifie et affiche si la partie est perdu
 * @param[in] g : la grille
 */
void jeuPerdu(Grille const& g)
{
    bool perdu = false;
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES]; i++)
    {
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++)
        {
            if(g.cases[i][j].estDesmasquee && g.cases[i][j].estMine)
                perdu = true;
            if(g.cases[i][j].estMarquee && !g.cases[i][j].estMine)
                perdu = true;
        }
    }

    if(perdu)
        cout << "game lost" << endl;
    else
        cout << "game not lost" << endl;
}

/**
 * @brief Verifie si le jeu est termine
 * @param[in] g : la grille 
 * @return true : si le jeu est termine
 * @return false : si le jeu n'est pas termine
 */
bool jeuFini(Grille const& g)
{
    bool fini = false;
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES]; i++)
    {
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++)
        {
            if(g.cases[i][j].estMarquee && !g.cases[i][j].estMine)
                fini = true;
            if(g.cases[i][j].estDesmasquee && g.cases[i][j].estMine)
                fini = true;
        }
    }
    return fini;
}

/**
 * @brief Recupere une grille avec le flot de sortie
 * @param[in,out] g : la grille 
 */
void extractionGrille(Grille& g, char chaine[MAX_SAISIE_DEMINEUR][MAX_SAISIE_DEMINEUR])
{
    int tmpLigne = 0;
    int tmpColonnes = 0;
    for(unsigned int i = 2; i < g.nbLignesColonnes[LIGNES] * 2 + 1; i += 2)
    {
        for(unsigned int j = 2; j < MAX_SAISIE_DEMINEUR; j += 4)
        {
            if(estChiffre(chaine[i][j]))
            {
                g.cases[tmpLigne][tmpColonnes].estMine = false;
                g.cases[tmpLigne][tmpColonnes].estMarquee = false;
                g.cases[tmpLigne][tmpColonnes].nbMines = ((int)chaine[i][j]) - 48;
                g.cases[tmpLigne][tmpColonnes].estDesmasquee = true;
                tmpColonnes++;
            }
            else if(chaine[i][j] == '.')
            {
                g.cases[tmpLigne][tmpColonnes].estMine = false;
                g.cases[tmpLigne][tmpColonnes].estMarquee = false;
                g.cases[tmpLigne][tmpColonnes].estDesmasquee = false;
                tmpColonnes++;
            }
            else if(chaine[i][j] == 'x')
            {
                g.cases[tmpLigne][tmpColonnes].estMine = false;
                g.cases[tmpLigne][tmpColonnes].estMarquee = true;
                g.cases[tmpLigne][tmpColonnes].estDesmasquee = false;
                tmpColonnes++;
            }
            else if(chaine[i][j] == ' ')
            {
                g.cases[tmpLigne][tmpColonnes].estMine = false;
                g.cases[tmpLigne][tmpColonnes].estMarquee = false;
                g.cases[tmpLigne][tmpColonnes].estDesmasquee = true;
                tmpColonnes++;
            }
        }
        tmpLigne++;
        tmpColonnes = 0;
    }
}

/**
 * @brief Ecrit dans le conteneur les positions des cases qui n'ont pas
 * encore ete demasquee, ni marquee
 * @param[in,out] g : la grille
 * @param[in,out] c : le conteneur
 */
void recupererCasesNonDemasquee(Grille& g, Conteneur& c)
{
    int tmp = 0;
    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES]; i++)
        for(unsigned int j = 0; j < g.nbLignesColonnes[COLONNES]; j++)
            if(!g.cases[i][j].estDesmasquee && !g.cases[i][j].estMarquee)
                ecrire(c, tmp++, i * g.nbLignesColonnes[COLONNES] + j);
}

/**
 * @brief Premiere commande qui permet de produire un probleme
 * avec un nombre de lignes, colonnes et mines
 * @param g : la grille utilisee
 */
void produireProbleme(Grille& g)
{
    initialiserProbleme(g);
    genererMines(g);
    compterMines(g);
    afficherProbleme(g);
}

/**
 * @brief Deuxieme commande produit une grille avec un probleme
 * et un historique de coups
 * @param g : la grille utilisee
 */
void produireGrille(Grille &g)
{
    saisieProbleme(g);
    afficher(g);
}

/**
 * @brief Troisieme commande determiner si la partie est gagnee
 * a partir d'un probleme et d'un historique de coups
 * @param g : la grille utilisee
 */
void determinerPartieGagne(Grille& g)
{
    saisieProbleme(g);
    jeuGagne(g);
}

/**
 * @brief Troisieme commande determiner si la partie est perdue
 * a partir d'un probleme et d'un historique de coups
 * @param g : la grille utilisee
 */
void determinerPartiePerdu(Grille& g)
{
    saisieProbleme(g);
    jeuPerdu(g);
}

/**
 * @brief Cinquieme commande produire un nouveau coup a partir
 * d'une grille
 * @param[in,out] g : la grille
 */
void ProduireCoupParOrdi(Grille& g)
{
    char affichageDemineur[MAX_SAISIE_DEMINEUR][MAX_SAISIE_DEMINEUR];
    Conteneur casesNonDemasquee;
    char action[2] = {'D', 'M'};

    cin >> g.nbLignesColonnes[LIGNES];
    cin >> g.nbLignesColonnes[COLONNES];
    for(unsigned int i = 0; i < MAX_SAISIE_DEMINEUR; i++)
        for(unsigned int j = 0; j < MAX_SAISIE_DEMINEUR; j++)
            affichageDemineur[i][j] = ' ';

    for(unsigned int i = 0; i < g.nbLignesColonnes[LIGNES] * 2 + 1; i++)
        cin.getline(affichageDemineur[i], MAX_SAISIE_DEMINEUR);
    extractionGrille(g, affichageDemineur);

    initialiser(casesNonDemasquee, 1, 1);
    recupererCasesNonDemasquee(g, casesNonDemasquee);
    cout << action[rand() % 2] << tirageAleatoire(casesNonDemasquee) << endl;

    detruire(casesNonDemasquee);
}