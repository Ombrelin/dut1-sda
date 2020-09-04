/**
*@TestLecture.cpp
*Projet SDA
*@author Maud Gellée
*@author Arsène Lapostolet
*@version 1 15/12/2017
*@brief lit dans le fichier et affiche le contenu à l'écran
*/

#include "PaquetReseau.h"
/*#include "IdentificateurMessage.h"
#include "BlocData.h"*/
#include "Messagerie.h"
#include <iostream>
#include <fstream>

//using namespace std;

int main() {
	PaquetReseau p;
	Messagerie m;
	//m.MessageEnCours = 0;
	//initialisation dela messagerie
	initialiser(m, 1, 1);
	//initialisation de la file de BlocData de MessageEnCours
	std::ifstream flotE;
	flotE.open("inSp5.txt", std::ios::in);
	if (flotE.fail()) {
		std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
		exit(1);
	}
	else {
		do {
			lire(flotE, p);
			//afficher(std::cout, p);
			TraiterPaquetReseau(m, p);
			//faire l'affichage quand un paquet réseau est traité

		} while (flotE.good());

		for (unsigned int i = 0; i<longueur(m.liste);++i) {
			afficher(std::cout, m.liste.c.tab[i].IdMes);
			std::cout << std::endl;
			for (unsigned int j = 0; j < m.liste.c.tab[i].lgMes; ++j) {
			std::cout << tete(lire(m.liste, i).fileB).data << std::endl;
			sortir(m.liste.c.tab[i].fileB);
			}
		}
	}

	flotE.close();
	detruire(m.liste);

	system("pause"); return 0;
}
