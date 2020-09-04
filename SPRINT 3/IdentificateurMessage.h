#pragma once
/**
* @IdentificateurMessage.h
* Projet SDA
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 14/12/2017
* @brief fichier d'ent�te des identificateurs des messages
*/

#pragma once
#ifndef _IDENTIFICATEURMESSAGE_
#define _IDENTIFICATEURMESSAGE_
#include <fstream>
#include <iostream>

/* Strcture de l'identificateur du message */
struct IdMessage {
	enum { MAXNOM = 80 };
	enum { MAXDH = 10 };
	char exp[MAXNOM + 1];
	char dest[MAXNOM + 1];
	char date[MAXDH];
	char heure[MAXDH];
};

/**
* @brief affiche l'identifiant d'un message
* @param [in-out] flux de sortie du programme
* @param [in] identifiant du message
*/
void afficher(std::ostream& os, IdMessage& idMes);

/**
* @brief r�cup�re l'identifiant du message dans un fichier
* @param [in-out] flux entr�e d'un fichier text
* @param [in-out] identifiant du message
*/
void lire(std::istream& is, IdMessage& idMes);

/**
* @brief compare deux Identificateurs messages
* @param [in] premier identifiant � comparer
* @param [in] deuxi�me id�tifiant � comparer
* @return renvoie un bool�en, 0 s'ils sont pareil, 1 sinon
*/
bool estEgal(const IdMessage& id1, const IdMessage& id2);

#endif