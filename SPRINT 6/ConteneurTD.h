#pragma once
#ifndef _CONTENEUR_TD_
#define _CONTENEUR_TD_

/**
* @file ConteneurTD.h
* Projet sem04-tp-Cpp3
* @author l'�quipe p�dagogique
* @version 1 19/12/05
* @brief Composant de conteneur d'Itemfs en m�moire dynamique � capacit� fixe
* Structures de donn�es et algorithmes - DUT1 Paris 5
*/

#include "Itemf.h"

/** @brief Type des conteneurs d'Itemfes allou�s en m�moire dynamique
*  et de capacit� fixe */
struct ConteneurTD {
	unsigned int capacite; 	// capacit� du conteneur (>0)
	Itemf* tab;				// tableau d'Itemfs allou� en m�moire dynamique
};

/**
* @brief Initialise un conteneur d'Itemfs vide
* Allocation en m�moire dynamique du conteneur d'Itemfs de capacit� capa
* @see detruire pour sa d�sallocation en fin d'utilisation
* @param[out] c : le conteneur d'Itemfs
* @param [in] capa : capacit� du tableau
* @pre capa>0
*/
void initialiser(ConteneurTD& c, unsigned int capa);

/**
* @brief D�salloue un conteneur d'Itemfs en m�moire dynamique
* @see initialiser le conteneur d'Itemfs a d�j� �t� allou�
* @param[out] c : le conteneur d'Itemfs
*/
void detruire(ConteneurTD& c);

/**
* @brief Lecture d'un Itemf dans un conteneur
* @param[in] c : le conteneur d'Itemfs
* @param[in] i : l'indice de l'Itemf dans le conteneur
* @return l'Itemf � la position i
* @pre i < c.capacite
*/
Itemf lire(const ConteneurTD& c, unsigned int i);

/**
* @brief Ecrire un Itemf dans un conteneur d'Itemfs
* @param[out] c : le conteneur d'Itemfs
* @param[in] i : la position o� ajouter/modifier l'Itemf
* @param[in] Itemf : l'Itemf � �crire
* @pre i < c.capacite
*/
void ecrire(ConteneurTD& t, unsigned int i, const Itemf& it);

#endif /*_CONTENEUR_TD_*/
