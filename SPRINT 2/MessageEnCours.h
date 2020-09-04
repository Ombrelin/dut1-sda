#pragma once
#ifndef _MESSAGEENCOURS_
#define _MESSAGEENCOURS_

/**
* @file MessageEnCours.h
* Projet SDA
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 16/12/2017
* @brief fichier d'entête des messages en cours
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
* @param le Message en cours à initialiser
*/
void initialiser(MessageEnCours& m);

/**
* @brief détruire un message en cours
* @param le Message en cours à détruire
*/
void detruire(MessageEnCours& m);

#endif