/**
* @file ConteneurTD.cpp
* Projet sem04-tp-Cpp3
* @author l'�quipe p�dagogique
* @version 1 19/12/05
* @brief Composant de conteneur d'Itemfs en m�moire dynamique � capacit� fixe
* Structures de donn�es et algorithmes - DUT1 Paris 5
*/

#include <iostream>
using namespace std;
#include <cassert>

#include "ConteneurTD.h"

/**
* @brief Initialise un conteneur d'Itemfs vide
* Allocation en m�moire dynamique du conteneur d'Itemfs de capacit� capa
* @see detruire pour sa d�sallocation en fin d'utilisation
* @param[out] c : le conteneur d'Itemfs
* @param [in] capa : capacit� du tableau
* @pre capa>0
*/
void initialiser(ConteneurTD& c, unsigned int capa) {
	assert(capa>0);
	c.capacite = capa;
	// arr�t du programme en cas d'erreur d'allocation
	c.tab = new Itemf[capa];
	/* Affichage pour une trace de l'allocation
	* Ne jamais faire d'affichage dans une fonction
	* dont ce n'est pas le r�le explicite */
	//cout << "Allocation de " << t.capacite*sizeof(Itemf)<< " octets"<< endl;
}

/**
* @brief D�salloue un conteneur d'Itemfs en m�moire dynamique
* @see initialiser le conteneur d'Itemfs a d�j� �t� allou�
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
* @return l'Itemf � la position i
* @pre i < c.capacite
*/
Itemf lire(const ConteneurTD& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

/**
* @brief Ecrire un Itemf dans un conteneur d'Itemfs
* @param[out] c : le conteneur d'Itemfs
* @param[in] i : la position o� ajouter/modifier l'Itemf
* @param[in] Itemf : l'Itemf � �crire
* @pre i < c.capacite
*/
void ecrire(ConteneurTD& c, unsigned int i, const Itemf& it) {
	assert(i < c.capacite);
	c.tab[i] = it;
}
