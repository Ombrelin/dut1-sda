/**
* @file Messagerie.cpp
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 - 19/12/2017
* @brief fichier de d�finition de messagerie (Composant de stockage des 
* messages en cours)
*/

#include "Messagerie.h"
#include "PaquetReseau.h"
#include <string>

/**
* @brief traite un paquet r�seau
* @param [in-out] messagerie concern�e
* @param [in-out] paquet r�seau � traiter
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