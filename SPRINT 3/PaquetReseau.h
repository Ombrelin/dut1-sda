#pragma once
/**
*@file PaquetReseau.h
* Projet SDA
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 14/12/2017
* @brief fichier d'entête des paquets réseau
*/

#pragma once
#ifndef _PAQUETRESEAU_
#define _PAQUETRESEAU_

#include "IdentificateurMessage.h"
#include "BlocData.h"
#include <fstream>

/*Structure du paquet-réseau*/
struct PaquetReseau {
	unsigned int noPR;
	IdMessage IdMes;
	BlocData blocD;
	unsigned int finMess;
};

/**
* @brief récupère un paquet réseau
* @param [in-out] flux entrée d'un fichier text
* @param [in-out] paquet réseau
*/
void lire(std::istream& is, PaquetReseau& packRes);

/**
* @brief affiche un paquet réseau
* @param [in-out] flux de sortie
* @param [in] paquet réseau
*/
void afficher(std::ostream& os, PaquetReseau& packRes);


#endif