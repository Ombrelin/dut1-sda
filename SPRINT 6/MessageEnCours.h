#pragma once
#ifndef _MESSAGEENCOURS_
#define _MESSAGEENCOURS_

/**
* @file MessageEnCours.h
* Projet SDA
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 16/12/2017
* @brief fichier d'ent�te des messages en cours
*/

#include "IdentificateurMessage.h"
#include "FileAPriorite.h"

struct MessageEnCours {
	IdMessage IdMes;
	File fileB;
	unsigned int lgMes;
	unsigned int nbPRecus;
	unsigned int LastPrecu;
};

/**
* @brief initialiser un message en cours
* @param le Message en cours � initialiser
*/
void initialiser(MessageEnCours& MesEnC/*, const PaquetReseau& p*/);

/**
* @brief d�truire un message en cours
* @param le Message en cours � d�truire
*/
void detruire(MessageEnCours& MesEnC);


#endif