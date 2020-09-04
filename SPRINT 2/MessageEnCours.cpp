/**
* @file MessageEnCours.cpp
* Projet SDA
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 16/12/2017
* @brief fichier de définition des messages en cours
*/

#include "MessageEnCours.h"

/**
* @brief initialiser un message en cours
* @param le Message en cours à initialiser
*/
void initialiser(MessageEnCours& m) {
	m.lgMes = 0;
	m.nbPRecus = 0;
	m.LastPrecu = 0;
}

/**
* @brief détruire un message en cours
* @param le Message en cours à détruire
*/
void detruire(MessageEnCours& m) {

}
