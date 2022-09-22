#include "HistoriqueDeCoups.hpp"

void ajouter(HistoriqueDeCoups& h, string coup)
{
    h.historique[h.nbCoups] = coup;
    h.nbCoups++;
}

void initialiser(HistoriqueDeCoups& h)
{
    h.nbCoups = 0;
    for(int i = 0; i < HistoriqueDeCoups::CAPACITE; i++)
        h.historique[i] = "";
}