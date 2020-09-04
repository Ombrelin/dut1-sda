/**
* @TestLecture.cpp
* Projet SDA
* @author Maud Gell�e
* @author Ars�ne Lapostolet
* @version 1 15/12/2017
* @brief lit dans le fichier et affiche le contenu � l'�cran
*/

#include "PaquetReseau.h"
#include "IdentificateurMessage.h"
#include "BlocData.h"
#include <iostream>
#include <fstream>

int main() {
	std::ifstream flotE;
	flotE.open("ligne.txt", std::ios::in);
	if (flotE.fail()) {
		std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
		exit(1);
	}
	else{
		PaquetReseau p;
		do {
			lire(flotE, p);
			afficher(std::cout, p); 
			std::cout << std::endl;
		}	while(flotE.good());
	flotE.close();
	}
	system("pause"); return 0;
}
