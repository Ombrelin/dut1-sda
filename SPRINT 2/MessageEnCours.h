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

struct MessageEnCours {
	IdMessage IdMes;
	unsigned int lgMes;
	unsigned int nbPRecus;
	unsigned int LastPrecu;
};

/**
* @brief initialiser un message en cours
* @param le Message en cours � initialiser
*/
void initialiser(MessageEnCours& m);

/**
* @brief d�truire un message en cours
* @param le Message en cours � d�truire
*/
void detruire(MessageEnCours& m);

#endif