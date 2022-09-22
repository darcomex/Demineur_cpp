#include "Conteneur.h"

/**
 * @brief Initialise un conteneur d'items
 * Allocation en m�moire dynamique du conteneur d'items
 * de capacit� (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa d�sallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacit� du conteneur
 * @param [in] p : pas d'extension de capacit�
 * @pre capa>0 et p>0
 */
void initialiser(Conteneur& c, unsigned int capa, unsigned int p) 
{
	assert((capa>0) && (p>0));
	c.capacite = capa;
	c.pasExtension = p;
	// arr�t du programme en cas d'erreur d'allocation
	c.tab = new ItemConteneur[capa];
}

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique
 * @see initialiser, le conteneur d'items a d�j� �t� allou� 
 * @param[out] c : le conteneur d'items
 */
void detruire(Conteneur& c) 
{
	delete [] c.tab;
	c.tab = NULL;
}

/**
 * @brief Lecture d'un item d'un conteneur d'items
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item � la position i
 * @pre i < c.capacite   
 */
ItemConteneur lire(const Conteneur& c, unsigned int i) 
{
	assert(i < c.capacite);
	return c.tab[i];
}

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] it : l'item � �crire 
 */
void ecrire(Conteneur& c, unsigned int i, const ItemConteneur& it) 
{
	if (i>=c.capacite) {
		/* Strat�gie de r�allocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille) 
		 * � i * c.pasExtension */
		unsigned int newTaille = (i+1) * c.pasExtension;
		/* Allouez en m�moire dynamique un nouveau tableau (newT) 
		 * � cette nouvelle taille*/
		ItemConteneur* newT = new ItemConteneur[newTaille];
		/* Recopiez les items d�j� stock�s dans le conteneur */
    	for (unsigned int i = 0; i < c.capacite; ++i)
      		newT[i] = c.tab[i];
      	/* D�sallouez l'ancien tableau support du conteneur */
    	delete [] c.tab;
    	/* Actualiser la mise � jour du conteneur en m�moire dynamique
    	 * Faites pointer le tableau support du conteneur 
    	 * sur le nouveau tableau en m�moire dynamique */
    	c.tab = newT;
    	/* Actualisez la taille du conteneur */
    	c.capacite = newTaille;
	}
	/* Ecriture de l'item (it) � la position i dans le conteneur */
	c.tab[i] = it;
}

/**
 * @brief Tire un item aleatoire dans le conteneur
 * @param[in] t : le conteneur
 * @return ItemConteneur : le nombre aleatoire
 */
ItemConteneur tirageAleatoire(Conteneur& t)
{
	return t.tab[rand() % t.capacite];
}