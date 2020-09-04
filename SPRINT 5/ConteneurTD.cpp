/**
* @file ConteneurTD.cpp
* Projet sem04-tp-Cpp3
* @author l'équipe pédagogique
* @version 1 19/12/05
* @brief Composant de conteneur d'Itemfs en mémoire dynamique à capacité fixe
* Structures de données et algorithmes - DUT1 Paris 5
*/

#include <iostream>
using namespace std;
#include <cassert>

#include "ConteneurTD.h"

/**
* @brief Initialise un conteneur d'Itemfs vide
* Allocation en mémoire dynamique du conteneur d'Itemfs de capacité capa
* @see detruire pour sa désallocation en fin d'utilisation
* @param[out] c : le conteneur d'Itemfs
* @param [in] capa : capacité du tableau
* @pre capa>0
*/
void initialiser(ConteneurTD& c, unsigned int capa) {
	assert(capa>0);
	c.capacite = capa;
	// arrêt du programme en cas d'erreur d'allocation
	c.tab = new Itemf[capa];
	/* Affichage pour une trace de l'allocation
	* Ne jamais faire d'affichage dans une fonction
	* dont ce n'est pas le rôle explicite */
	//cout << "Allocation de " << t.capacite*sizeof(Itemf)<< " octets"<< endl;
}

/**
* @brief Désalloue un conteneur d'Itemfs en mémoire dynamique
* @see initialiser le conteneur d'Itemfs a déjà été alloué
* @param[out] c : le conteneur d'Itemfs
*/
void detruire(ConteneurTD& c) {
	delete[] c.tab;
	c.tab = NULL;
}

/**
* @brief Lecture d'un Itemf dans un conteneur
* @param[in] c : le conteneur d'Itemfs
* @param[in] i : l'indice de l'Itemf dans le conteneur
* @return l'Itemf à la position i
* @pre i < c.capacite
*/
Itemf lire(const ConteneurTD& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

/**
* @brief Ecrire un Itemf dans un conteneur d'Itemfs
* @param[out] c : le conteneur d'Itemfs
* @param[in] i : la position où ajouter/modifier l'Itemf
* @param[in] Itemf : l'Itemf à écrire
* @pre i < c.capacite
*/
void ecrire(ConteneurTD& c, unsigned int i, const Itemf& it) {
	assert(i < c.capacite);
	c.tab[i] = it;
}
