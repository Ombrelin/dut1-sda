#pragma once
/**
*@file PaquetReseau.h
* Projet SDA
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 14/12/2017
* @brief fichier d'ent�te des paquets r�seau
*/

#pragma once
#ifndef _PAQUETRESEAU_
#define _PAQUETRESEAU_

#include "IdentificateurMessage.h"
#include "BlocData.h"
#include <fstream>

/*Structure du paquet-r�seau*/
struct PaquetReseau {
	unsigned int noPR;
	IdMessage IdMes;
	BlocData blocD;
	unsigned int finMess;
};

/**
* @brief r�cup�re un paquet r�seau
* @param [in-out] flux entr�e d'un fichier text
* @param [in-out] paquet r�seau
*/
void lire(std::istream& is, PaquetReseau& packRes);

/**
* @brief affiche un paquet r�seau
* @param [in-out] flux de sortie
* @param [in] paquet r�seau
*/
void afficher(std::ostream& os, PaquetReseau& packRes);


#endif