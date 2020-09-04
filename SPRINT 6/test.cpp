/**
*@TestLecture.cpp
*Projet SDA
*@author Maud Gellée
*@author Arsène Lapostolet
*@version 1 15/12/2017
*@brief lit dans le fichier et affiche le contenu à l'écran
*/

#include "PaquetReseau.h"
#include "Messagerie.h"
#include <iostream>
#include <fstream>

int main() {
	PaquetReseau p;
	Messagerie m;
	initialiser(m, 1, 1);
	std::ofstream log("log.txt", std::ios::app);
	std::ifstream flotE;
	flotE.open("inSp6.txt", std::ios::in);
	if (flotE.fail()) {
		std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
		exit(1);
	}
	else {
		do {
			lire(flotE, p);
			TraiterPaquetReseau(m, p);
		} while (flotE.good());

		log << "Fin de transmission";
		for (unsigned int j = 0; j < longueur(m.liste); ++j) {
			if (!estVide(m.liste.c.tab[j].fileB)) {
				log << ", suppression de message ";
				afficher(log,m.liste.c.tab[j].IdMes);
				log << std::endl;
				supprimer(m.liste, j);
			}
		}
	}
	log.close();
	flotE.close();
	detruire(m.liste);

	system("pause"); return 0;
}
