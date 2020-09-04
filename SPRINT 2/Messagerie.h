/**
* @file Messagerie.h
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 - 19/12/2017
* @brief fichier d'ent�te de Mesagerie (Composant de stockage des messages en 
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
* @brief traite un paquet r�seau
* @param [in-out] messagerie concern�e
* @param [in-out] paquet r�seau � traiter
*/
void TraiterPaquetReseau(Messagerie& Mes, PaquetReseau& packRes);

#endif