/**
* @IdentificateurMessage.cpp
* Projet SDA
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 14/12/2017
* @brief fichier de définition des identificateurs de messages
*/

#include <iostream>
#include <fstream>
#include <cassert>
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
* @brief récupère l'identifiant du message dans un fichier
* @param [in-out] flux entrée d'un fichier text
* @param [in-out] identifiant du message
*/
void afficher(std::ostream& os, IdMessage& idMes){
	os << idMes.exp<< " " << idMes.dest << " " << idMes.date << " " << idMes.heure << " ";
}