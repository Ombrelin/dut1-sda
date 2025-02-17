#pragma once
#ifndef _FILE_
#define _FILE_

/**
* @file File.h
* Projet sem06-cours-Cpp1
* @author l'�quipe p�dagogique
* @version 2 - 13/01/10
* @brief Composant de file dont le conteneur est
* un tableau circulaire en m�moire dynamique avec capacit� param�tr�e
* Structures de donn�es et algorithmes - DUT1 Paris 5
*/

#include "ConteneurTD.h"

struct File {
	ConteneurTD c;	 // conteneur des �l�ments de file
	unsigned int indPremier; // index de la t�te de file dans tab
	unsigned int indProchain;// index du prochain �l�ment entr� en file
	unsigned int nb;		 // nombre d'�l�ments dans la file
};

/**
* @brief initialiser une file vide
* la file est allou�e en m�moire dynamique
* @see detruire, elle est � d�sallouer en fin d�utilisation
* @param[out] f : la file � initialiser
* @param[in] capa : capacit� de la file (nb maximum d�Itemfs stock�s)
* @pre capa>0
*/
void initialiser(File& f, unsigned int capa);

/**
* @brief D�sallouer une file
* @see initialiser, la file a d�j� �t� allou�e en m�moire dynamique
* @param[out] f : la file
*/
void detruire(File& f);

/**
* @brief Test de file pleine
* @param[in] f : la file test�e
* @return true si f est pleine, false sinon
*/
bool estPleine(const File& f);

/**
* @brief Test de file vide
* @param[in] f : la file test�e
* @return true si f est vide, false sinon
*/
bool estVide(const File& f);

/**
* @brief Lire l'Itemf en t�te de file
* @param[in] f : la file
* @return la valeur de l'Itemf en t�te de file
* @pre la file n�est pas vide
*/
Itemf tete(const File& f);

/**
* @brief Entrer un Itemf dans la file
* @param[in,out] f : la file
* @param[in] it : l'Itemf � entrer
* @pre f n�est pas pleine
*/
void entrer(File& f, const Itemf& it);

/**
* @brief Sortir l�Itemf t�te de file
* @param[in,out] f : la file
* @pre f n�est pas vide
*/
void sortir(File& f);

#endif