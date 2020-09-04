/**
* @TestLecture.cpp
* Projet SDA
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 15/12/2017
* @brief lit dans le fichier et affiche les iditificateurs des messages à 
* l'écran
*/

#include "PaquetReseau.h"
#include "Messagerie.h"
#include <iostream>
#include <fstream>

int main() {
	PaquetReseau p;
	Messagerie m;
	initialiser(m.liste, 1, 1);
	std::ifstream flotE;
	flotE.open("ligne.txt", std::ios::in);
	if (flotE.fail()) {
		std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
		exit(1);
	}
	else {
		do {
			lire(flotE, p);
			TraiterPaquetReseau(m, p);
			
		} while (flotE.good());
		
		for (unsigned int i = 0; i + 1 < longueur(m.liste); ++i) {
			std::cout << "m.idMessage[" << i << "]=|";
			afficher(std::cout, m.liste.c.tab[i].IdMes);
			std::cout << "|" << std::endl;
		}
		
	}
	flotE.close();
	detruire(m.liste);
	
	system("pause"); return 0;
}
