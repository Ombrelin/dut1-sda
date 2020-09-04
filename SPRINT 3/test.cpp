/**
*@TestLecture.cpp
*Projet SDA
*@author Maud Gell�e
*@author Ars�ne Lapostolet
*@version 1 15/12/2017
*@brief lit dans le fichier et affiche le contenu � l'�cran
*/

#include "PaquetReseau.h"
#include "Messagerie.h"
#include <iostream>
#include <fstream>

int main() {
	PaquetReseau p;
	Messagerie m;
	initialiser(m, 1, 1);
	std::ifstream flotE;
	flotE.open("inSp3.txt", std::ios::in);
	if (flotE.fail()) {
		std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
		exit(1);
	}
	else {
		do {
			lire(flotE, p);
			TraiterPaquetReseau(m, p);
			//faire l'affichage quand un paquet r�seau est trait�

		} while (flotE.good());
	}
	flotE.close();
	detruire(m.liste);

	system("pause"); return 0;
}
