#pragma once
/**
* @file Messagerie.h
* @author Maud Gell�e
* @author Ars�ne Lapostolet
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
* @brief traite un paquet r�seau
* @param [in-out] messagerie concern�e
* @param [in-out] paquet r�seau � traiter
*/
void TraiterPaquetReseau(Messagerie& Mes, PaquetReseau& packRes);

/**
* @brief Initialise une messagerie
* @param [in-out] la messagerie � initiliser
* @param [in] la capacit� de la liste de cette messagerie
* @param [in] pas d'extension de liste de cette messagerie
*/
void initialiser(Messagerie& m, unsigned int capa, unsigned int pas);

/**
* @brief d�salloue une messagerie
* @param [in-out] la messagerie � d�sallouer
*/
void detruire(Messagerie& m);

#endif