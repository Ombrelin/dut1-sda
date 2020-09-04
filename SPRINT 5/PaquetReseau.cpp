/**
*@file PaquetReseau.cpp
*Projet SDA
*@author Maud Gell�e
*@author Ars�ne Lapostolet
*@version 1 14/12/2017
*@brief fichier de d�finition des paquets r�seau
*/

#include <iostream>
#include <fstream>
#include "PaquetReseau.h"
#include "BlocData.h"
#include "IdentificateurMessage.h"

/**
* @brief r�cup�re un paquet r�seau
* @param [in-out] flux entr�e d'un fichier text
* @param [in-out] paquet r�seau
*/
void lire(std::istream& is, PaquetReseau& packRes) {
	is >> packRes.noPR;
	lire(is, packRes.IdMes);
	is >> packRes.finMess;
	lire(is, packRes.blocD);
}

/**
* @brief affiche un paquet r�seau
* @param [in-out] flux de sortie
* @param [in] paquet r�seau
*/
void afficher(std::ostream& os, PaquetReseau& packRes) {
	os << packRes.noPR;
	os << " ";
	afficher(os, packRes.IdMes);
	os << packRes.finMess;
	os << " ";
	afficher(os, packRes.blocD);
}
