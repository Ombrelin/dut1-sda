/**
* @file MessageEnCours.cpp
* Projet SDA
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 16/12/2017
* @brief fichier de d�finition des messages en cours
*/

#include "MessageEnCours.h"

/**
* @brief initialiser un message en cours
* @param le Message en cours � initialiser
*/
void initialiser(MessageEnCours& m) {
	m.lgMes = 0;
	m.nbPRecus = 0;
	m.LastPrecu = 0;
}

/**
* @brief d�truire un message en cours
* @param le Message en cours � d�truire
*/
void detruire(MessageEnCours& m) {

}
