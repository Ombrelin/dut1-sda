/**
* @file Messagerie.h
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 - 19/12/2017
* @brief fichier d'entête de Mesagerie (Composant de stockage des messages en 
* cours)
*/

#pragma once
#ifndef _MESSAGERIE_
#define _MESSAGERIE_

#include "Liste.h"
#include "PaquetReseau.h"

/*Structure de Messagerie*/
struct Messagerie {
	Liste liste;
};

/**
* @brief traite un paquet réseau
* @param [in-out] messagerie concernée
* @param [in-out] paquet réseau à traiter
*/
void TraiterPaquetReseau(Messagerie& Mes, PaquetReseau& packRes);

#endif