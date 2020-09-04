#pragma once
/**
* @file Messagerie.h
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 - 19/12/2017
* @brief Composant de stockage des messages en cours
*/

#pragma once
#ifndef _MESSAGERIE_
#define _MESSAGERIE_

#include "Liste.h"
#include "PaquetReseau.h"

struct Messagerie {
	Liste liste;
};

/**
* @brief traite un paquet réseau
* @param [in-out] messagerie concernée
* @param [in-out] paquet réseau à traiter
*/
void TraiterPaquetReseau(Messagerie& Mes, PaquetReseau& packRes);

/**
* @brief Initialise une messagerie
* @param [in-out] la messagerie à initiliser
* @param [in] la capacité de la liste de cette messagerie
* @param [in] pas d'extension de liste de cette messagerie
*/
void initialiser(Messagerie& m, unsigned int capa, unsigned int pas);

/**
* @brief désalloue une messagerie
* @param [in-out] la messagerie à désallouer
*/
void detruire(Messagerie& m);

#endif