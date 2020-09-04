#pragma once
/**
*@file BlocData.h
*Projet SDA
*@author Maud Gellée
*@author Arsène Lapostolet
*@version 1 14/12/2017
*@brief fichier d'entête des blocs de données (contenu des messages)
*/

#pragma once
#ifndef _BLOCDATA_
#define _BLOCDATA_
#include <fstream>

/*Structure Bloc de donnée (contenu du message)*/
struct BlocData {
	enum { LGMSG = 21 };
	unsigned int noBloc;
	char data[LGMSG];
};

/**
*@brief lis un Bloc de donnée de message dans le fichier
*@param [in-out] flux d'entrée
*@param [in-out] bloc de donnée
*/
void lire(std::istream& is, BlocData& blocD);

/**
*@brief envoie un bloc de donnée de message dans un flux de sortie
*@param [in-out] flux de sortie
*@param [[in] bloc de donnée à envoyer
*/
void afficher(std::ostream& os, BlocData& blocD);

/**
*@brief permet de nettoyer la ligne d'un flux d'entrée pour finir une ligne sa
*ns supprimer les espaces
*@param [in-out] flux d'entrée
*/
void nettoyerLigne(std::istream& is);
#endif