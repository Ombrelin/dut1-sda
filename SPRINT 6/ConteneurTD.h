#pragma once
#ifndef _CONTENEUR_TD_
#define _CONTENEUR_TD_

/**
* @file ConteneurTD.h
* Projet sem04-tp-Cpp3
* @author l'équipe pédagogique
* @version 1 19/12/05
* @brief Composant de conteneur d'Itemfs en mémoire dynamique à capacité fixe
* Structures de données et algorithmes - DUT1 Paris 5
*/

#include "Itemf.h"

/** @brief Type des conteneurs d'Itemfes alloués en mémoire dynamique
*  et de capacité fixe */
struct ConteneurTD {
	unsigned int capacite; 	// capacité du conteneur (>0)
	Itemf* tab;				// tableau d'Itemfs alloué en mémoire dynamique
};

/**
* @brief Initialise un conteneur d'Itemfs vide
* Allocation en mémoire dynamique du conteneur d'Itemfs de capacité capa
* @see detruire pour sa désallocation en fin d'utilisation
* @param[out] c : le conteneur d'Itemfs
* @param [in] capa : capacité du tableau
* @pre capa>0
*/
void initialiser(ConteneurTD& c, unsigned int capa);

/**
* @brief Désalloue un conteneur d'Itemfs en mémoire dynamique
* @see initialiser le conteneur d'Itemfs a déjà été alloué
* @param[out] c : le conteneur d'Itemfs
*/
void detruire(ConteneurTD& c);

/**
* @brief Lecture d'un Itemf dans un conteneur
* @param[in] c : le conteneur d'Itemfs
* @param[in] i : l'indice de l'Itemf dans le conteneur
* @return l'Itemf à la position i
* @pre i < c.capacite
*/
Itemf lire(const ConteneurTD& c, unsigned int i);

/**
* @brief Ecrire un Itemf dans un conteneur d'Itemfs
* @param[out] c : le conteneur d'Itemfs
* @param[in] i : la position où ajouter/modifier l'Itemf
* @param[in] Itemf : l'Itemf à écrire
* @pre i < c.capacite
*/
void ecrire(ConteneurTD& t, unsigned int i, const Itemf& it);

#endif /*_CONTENEUR_TD_*/
