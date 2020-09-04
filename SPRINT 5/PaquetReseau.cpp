/**
*@file PaquetReseau.cpp
*Projet SDA
*@author Maud Gellée
*@author Arsène Lapostolet
*@version 1 14/12/2017
*@brief fichier de définition des paquets réseau
*/

#include <iostream>
#include <fstream>
#include "PaquetReseau.h"
#include "BlocData.h"
#include "IdentificateurMessage.h"

/**
* @brief récupère un paquet réseau
* @param [in-out] flux entrée d'un fichier text
* @param [in-out] paquet réseau
*/
void lire(std::istream& is, PaquetReseau& packRes) {
	is >> packRes.noPR;
	lire(is, packRes.IdMes);
	is >> packRes.finMess;
	lire(is, packRes.blocD);
}

/**
* @brief affiche un paquet réseau
* @param [in-out] flux de sortie
* @param [in] paquet réseau
*/
void afficher(std::ostream& os, PaquetReseau& packRes) {
	os << packRes.noPR;
	os << " ";
	afficher(os, packRes.IdMes);
	os << packRes.finMess;
	os << " ";
	afficher(os, packRes.blocD);
}
