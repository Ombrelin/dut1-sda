/**
*@file BlocData.cpp
*Projet SDA
*@author Maud Gell�e
*@author Ars�ne Lapostolet
*@version 1 14/12/2017
*@brief fichier de d�finition des blocs de donn�es (contenu des messages)
*/

#include <iostream>
#include <fstream>
#include "BlocData.h"

/**
*@brief lis un Bloc de donn�e de message dans le fichier
*@param [in-out] flux d'entr�e
*@param [in-out] bloc de donn�e
*/
void lire(std::istream& is, BlocData& blocD) {
	is >> blocD.noBloc;
	nettoyerLigne(is);
	is.getline(blocD.data, BlocData::LGMSG);
}

/**
*@brief envoie un bloc de donn�e de message dans un flux de sortie
*@param [in-out] flux de sortie
*@param [[in] bloc de donn�e � envoyer
*/
void afficher(std::ostream& os, BlocData& blocD) {
	os << blocD.noBloc << std::endl;
	os << blocD.data << std::endl;
}

/**
*@brief permet de nettoyer la ligne d'un flux d'entr�e pour finir une ligne sa
*ns supprimer les espaces
*@param [in-out] flux d'entr�e
*/
void nettoyerLigne(std::istream& is) {
	is.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}