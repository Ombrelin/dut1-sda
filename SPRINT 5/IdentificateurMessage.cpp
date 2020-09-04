/**
*@IdentificateurMessage.cpp
*Projet SDA
*@author Maud Gell�e
*@author Ars�ne Lapostolet
*@version 1 14/12/2017
*@brief fichier de d�finition des identificateurs de messages
*/

#include <iostream>
#include <fstream>
#include "IdentificateurMessage.h"

/**
* @brief affiche l'identifiant d'un message
* @param [in-out] flux de sortie du programme
* @param [in] identifiant du message
*/
void lire(std::istream& is, IdMessage& idMes) {
	is >> idMes.exp >> idMes.dest >> idMes.date >> idMes.heure;
}

/**
* @brief r�cup�re l'identifiant du message dans un fichier
* @param [in-out] flux entr�e d'un fichier text
* @param [in-out] identifiant du message
*/
void afficher(std::ostream& os, IdMessage& idMes) {
	os << idMes.exp << " " << idMes.dest << " " << idMes.date << " " << idMes.heure/*<<std::endl*/;
}

/**
* @brief compare deux Identificateurs messages
* @param [in] premier identifiant � comparer
* @param [in] deuxi�me id�tifiant � comparer
* @return renvoie un bool�en, 0 s'ils sont pareil, 1 sinon
*/
bool estEgal(const IdMessage& id1, const IdMessage& id2) {
	if ((strcmp(id1.dest, id2.dest) == 0) &&
		(strcmp(id1.exp, id2.exp) == 0) &&
		(strcmp(id1.date, id2.date) == 0) &&
		(strcmp(id1.heure, id2.heure) == 0)) {
		return true;
	}
	else {
		return false;
	}
}