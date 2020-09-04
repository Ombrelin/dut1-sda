/**
* @file Messagerie.cpp
* @author Maud Gellée
* @author Arsène Lapostolet
* @version 1 - 19/12/2017
* @brief Composant de stockage des messages en cours
*/

#include "Messagerie.h"
#include "PaquetReseau.h"
#include <string>
#include <fstream>

/**
* @brief traite un paquet réseau
* @param [in-out] messagerie concernée
* @param [in-out] paquet réseau à traiter
*/
void TraiterPaquetReseau(Messagerie& Mes, PaquetReseau& packRes) {
	unsigned int i;
	std::ofstream log("log.txt", std::ios::app);
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
		log << packRes.noPR << " Detection de nouveau message ";

		/*std::string grp = packRes.IdMes.dest;
		std::ofstream Mailbox("Mailbox" + grp + ".txt", std::ios::out);
		Mailbox << "Mailbox " << grp << std::endl;*/
		afficher(log, packRes.IdMes);
		log << " " << packRes.finMess << " " << packRes.blocD.noBloc
			<< std::endl;
		if (packRes.finMess == 1) {
			Mes.liste.c.tab[i].lgMes = packRes.blocD.noBloc;
			log << packRes.noPR << " Detection de fin de message ";
			afficher(log, packRes.IdMes);
			log << " " << packRes.finMess << " " << packRes.blocD.noBloc
				<< std::endl;
		}
	}
	else {
			entrer(Mes.liste.c.tab[i].fileB, packRes.blocD);
			(Mes.liste.c.tab[i].nbPRecus)++;
			Mes.liste.c.tab[i].LastPrecu = packRes.noPR;
			if (packRes.finMess == 1) {
				Mes.liste.c.tab[i].lgMes = packRes.blocD.noBloc;
				log << packRes.noPR << " Detection de fin de message ";
				afficher(log, packRes.IdMes);
				log << " " << packRes.finMess << " " << packRes.blocD.noBloc
					<< std::endl;
			}
		}
	if ((lire(Mes.liste, i).lgMes == lire(Mes.liste, i).nbPRecus)) {

		log << packRes.noPR << " Archivage mailbox ";
		log << packRes.IdMes.dest << " " << packRes.IdMes.date << " " << 
			packRes.IdMes.heure << std::endl;

		std::string grp= packRes.IdMes.dest;
		char read[8];
		char mail [8] = "Mailbox";
		//std::cout << mail;
		std::ofstream Mailbox ("Mailbox" + grp + ".txt", std::ios::app);
		std::ifstream Mailboxin("Mailbox" + grp + ".txt");
		//std::ifstream read1;
		Mailboxin.getline(read, 8);
		std::cout << read;
		if (strcmp(read, mail)!=0) {
			Mailbox << "Mailbox " << grp << std::endl;
		}
		afficher(std::cout, Mes.liste.c.tab[i].IdMes);
		afficher (Mailbox, Mes.liste.c.tab[i].IdMes);
		std::cout << std::endl;
		Mailbox << std::endl;
		for (unsigned int j = 0; j < Mes.liste.c.tab[i].lgMes; ++j) {
			std::cout << tete(lire(Mes.liste, i).fileB).data;
			Mailbox << tete(lire(Mes.liste, i).fileB).data;
			sortir(Mes.liste.c.tab[i].fileB);
			Mes.liste.c.tab[i].nbPRecus--;
		}
		std::cout << std::endl << std::endl;
		Mailbox << std::endl;
		Mailbox.close();
	}

	for (unsigned int j = 0; j < longueur(Mes.liste); ++j) {
		if (packRes.noPR >= lire(Mes.liste, j).LastPrecu + 10) {
			//mettre à jour log
			log << packRes.noPR << " Perte de paquet, suppression de message ";
			afficher(log, Mes.liste.c.tab[j].IdMes);
			log << std::endl;
			supprimer(Mes.liste, j);
		}
	}
	
}

/**
* @brief Initialise une messagerie
* @param [in-out] la messagerie à initiliser
* @param [in] la capacité de la liste de cette messagerie
* @param [in] pas d'extension de liste de cette messagerie
*/
void initialiser(Messagerie& m, unsigned int capa, unsigned int pas) {
	initialiser(m.liste, capa, pas);
}

/**
* @brief désalloue une messagerie
* @param [in-out] la messagerie à désallouer
*/
void detruire(Messagerie& m) {
	detruire(m.liste);
}