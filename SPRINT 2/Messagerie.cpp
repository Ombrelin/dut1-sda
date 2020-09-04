/**
* @file Messagerie.cpp
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 - 19/12/2017
* @brief fichier de définition de messagerie (Composant de stockage des 
* messages en cours)
*/

#include "Messagerie.h"
#include "PaquetReseau.h"
#include <string>

/**
* @brief traite un paquet réseau
* @param [in-out] messagerie concernée
* @param [in-out] paquet réseau à traiter
*/
void TraiterPaquetReseau(Messagerie& Mes, PaquetReseau& packRes) {
	
		unsigned int i;
		for (i = 0; i < longueur(Mes.liste); ++i) {
			if (estEgal(Mes.liste.c.tab[i].IdMes ,packRes.IdMes) == true) {
				break;
			}
		}
		if (i == longueur(Mes.liste)) {
			MessageEnCours m;
			m.IdMes = packRes.IdMes;
			inserer(Mes.liste, i, m);
		}
}