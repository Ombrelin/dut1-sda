/**
*@file MessageEnCours.cpp
*Projet SDA
*@author Maud Gell�e
*@author Ars�ne Lapostolet
*@version 1 16/12/2017
*@brief fichier de d�finition des messages en cours
*/

#include "MessageEnCours.h"
#include "PaquetReseau.h"

/**
*@brief initialiser un message en cours
*@param le Message en cours � initialiser
*/
void initialiser(MessageEnCours& MesEnC/*, const PaquetReseau& p*/) {
	MesEnC.lgMes = 0;
	MesEnC.nbPRecus = 0;
	MesEnC.LastPrecu = 0;
	enum { MAXFILE = 50 };
	initialiser(MesEnC.fileB, MAXFILE);
}

/**
*@brief d�truire un message en cours
*@param le Message en cours � d�truire
*/
void detruire(MessageEnCours& MesEnC) {
	detruire(MesEnC.fileB);
}