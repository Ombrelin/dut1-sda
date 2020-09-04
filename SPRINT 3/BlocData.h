#pragma once
/**
*@file BlocData.h
*Projet SDA
*@author Maud Gell�e
*@author Ars�ne Lapostolet
*@version 1 14/12/2017
*@brief fichier d'ent�te des blocs de donn�es (contenu des messages)
*/

#pragma once
#ifndef _BLOCDATA_
#define _BLOCDATA_
#include <fstream>

/*Structure Bloc de donn�e (contenu du message)*/
struct BlocData {
	enum { LGMSG = 21 };
	unsigned int noBloc;
	char data[LGMSG];
};

/**
*@brief lis un Bloc de donn�e de message dans le fichier
*@param [in-out] flux d'entr�e
*@param [in-out] bloc de donn�e
*/
void lire(std::istream& is, BlocData& blocD);

/**
*@brief envoie un bloc de donn�e de message dans un flux de sortie
*@param [in-out] flux de sortie
*@param [[in] bloc de donn�e � envoyer
*/
void afficher(std::ostream& os, BlocData& blocD);

/**
*@brief permet de nettoyer la ligne d'un flux d'entr�e pour finir une ligne sa
*ns supprimer les espaces
*@param [in-out] flux d'entr�e
*/
void nettoyerLigne(std::istream& is);
#endif