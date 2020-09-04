/**
*@file BlocData.cpp
*Projet SDA
*@author Maud Gellée
*@author Arsène Lapostolet
*@version 1 14/12/2017
*@brief fichier de définition des blocs de données (contenu des messages)
*/

#include <iostream>
#include <fstream>
#include "BlocData.h"

/**
*@brief lis un Bloc de donnée de message dans le fichier
*@param [in-out] flux d'entrée
*@param [in-out] bloc de donnée
*/
void lire(std::istream& is, BlocData& blocD) {
	is >> blocD.noBloc;
	nettoyerLigne(is);
	is.getline(blocD.data, BlocData::LGMSG);
}

/**
*@brief envoie un bloc de donnée de message dans un flux de sortie
*@param [in-out] flux de sortie
*@param [[in] bloc de donnée à envoyer
*/
void afficher(std::ostream& os, BlocData& blocD) {
	os << blocD.noBloc << std::endl;
	os << blocD.data << std::endl;
}

/**
*@brief permet de nettoyer la ligne d'un flux d'entrée pour finir une ligne sa
*ns supprimer les espaces
*@param [in-out] flux d'entrée
*/
void nettoyerLigne(std::istream& is) {
	is.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}