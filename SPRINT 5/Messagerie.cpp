/**
* @file Messagerie.cpp
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 - 19/12/2017
* @brief Composant de stockage des messages en cours
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
		if (estEgal(Mes.liste.c.tab[i].IdMes, packRes.IdMes) == true) {
			break;
		}
	}
	if (i == longueur(Mes.liste)) {
		MessageEnCours m;
		initialiser(m);
		m.IdMes = packRes.IdMes;
		m.nbPRecus = 1;
		m.LastPrecu = packRes.noPR;
		inserer(Mes.liste, i, m);
		entrer(Mes.liste.c.tab[i].fileB, packRes.blocD);
		if (packRes.finMess == 1) {
			Mes.liste.c.tab[i].lgMes = packRes.blocD.noBloc;
		}
	}
	else {
		entrer(Mes.liste.c.tab[i].fileB, packRes.blocD);
		(Mes.liste.c.tab[i].nbPRecus)++;
		Mes.liste.c.tab[i].LastPrecu = packRes.noPR;
		if (packRes.finMess == 1) {
			Mes.liste.c.tab[i].lgMes = packRes.blocD.noBloc;
		}
	}
	/*if ((lire(Mes.liste, i).lgMes == lire(Mes.liste, i).nbPRecus)) {
		afficher(std::cout, Mes.liste.c.tab[i].IdMes);
		std::cout << std::endl;
		for (unsigned int j = 0; j < Mes.liste.c.tab[i].lgMes; ++j) {
			std::cout << tete(lire(Mes.liste, i).fileB).data << std::endl;
			sortir(Mes.liste.c.tab[i].fileB);
		}
	}*/
}

/**
* @brief Initialise une messagerie
* @param [in-out] la messagerie � initiliser
* @param [in] la capacit� de la liste de cette messagerie
* @param [in] pas d'extension de liste de cette messagerie
*/
void initialiser(Messagerie& m, unsigned int capa, unsigned int pas) {
	initialiser(m.liste, capa, pas);
}

/**
* @brief d�salloue une messagerie
* @param [in-out] la messagerie � d�sallouer
*/
void detruire(Messagerie& m) {
	detruire(m.liste);
}