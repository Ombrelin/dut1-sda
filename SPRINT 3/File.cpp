/**
* @file File.cpp
* Projet sem06-cours-Cpp1
* @author l'�quipe p�dagogique
* @version 2 - 13/01/10
* @brief Composant de file avec capacit� param�tr�e
* Structures de donn�es et algorithmes - DUT1 Paris 5
*/

#include <cassert>
#include "File.h"

/**
* @brief initialiser une file vide
* la file est allou�e en m�moire dynamique
* @see detruire, elle est � d�sallouer en fin d�utilisation
* @param[out] f : la file � initialiser
* @param[in] capa : capacit� de la file (nb maximum d�Itemfs stock�s)
* @pre capa>0
*/
void initialiser(File& f, unsigned int capa) {
	assert(capa>0);
	initialiser(f.c, capa); // @see initialiser de ConteneurTD
	f.indPremier = 0;
	f.indProchain = 0;
	f.nb = 0;
}

/**
* @brief D�sallouer une file
* @see initialiser, la file a d�j� �t� allou�e en m�moire dynamique
* @param[out] f : la file
*/
void detruire(File& f) {
	detruire(f.c); // @see detruire de ConteneurTD
}

/**
* @brief Test de file pleine
* @param[in] f : la file test�e
* @return true si f est pleine, false sinon
*/
bool estPleine(const File& f) {
	return (f.nb == f.c.capacite); // @see type ConteneurTD 
}

/**
* @brief Test de file vide
* @param[in] f : la file test�e
* @return true si f est vide, false sinon
*/
bool estVide(const File& f) {
	return (f.nb == 0);
}

/**
* @brief Lire l'Itemf en t�te de file
* @param[in] f : la file
* @return la valeur de l'Itemf en t�te de file
* @pre la file n�est pas vide
*/
Itemf tete(const File& f) {
	assert(!estVide(f));
	return lire(f.c, f.indPremier); // @see lire, dans ConteneurTD 
}

/**
* @brief Entrer un Itemf dans la file
* @param[in,out] f : la file
* @param[in] it : l'Itemf � entrer
* @pre f n�est pas pleine
*/
void entrer(File& f, const Itemf& it) {
	assert(!estPleine(f));
	ecrire(f.c, f.indProchain, it); //@see ecrire de ConteneurTD 
	f.indProchain = (f.indProchain + 1) % f.c.capacite;
	f.nb++;
}

/**
* @brief Sortir l�Itemf t�te de file
* @param[in,out] f : la file
* @pre f n�est pas vide
*/
void sortir(File& f) {
	assert(!estVide(f));
	f.indPremier = (f.indPremier + 1) % f.c.capacite;;
	f.nb--;
}


