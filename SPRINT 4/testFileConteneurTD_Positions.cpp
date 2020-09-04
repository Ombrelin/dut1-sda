/**
 * @file testFilePositions.cpp
 * Projet sem06-cours-Cpp1
 * @author l'�quipe p�dagogique 
 * @version 1 - 25/01/06
 * @brief Test d'une file de positions dont le conteneur est
 * un tableau circulaire � capacit� fix�e en m�moire dynamique
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */
 
#include <iostream>
using namespace std;
 
#include "File.h"

/* Test d'une file (en m�moire dynamique et � capacit� param�tr�e
 * d'�l�ments de type Position */ 
int main() {

	File fPositions; // D�claration de la file de positions
	Position p;
	
	/* Initialisation de la file de capacit� 5 */ 
	initialiser(fPositions, 5);
	
	cout << "Test de la file de positions" << endl;
	
	/* Test de file vide */ 
	cout << "D�but de l'application : ";
	if (estVide(fPositions)) cout << "la file est vide" << endl;
	else cout << "la file n'est pas vide" << endl;
	
	/* Ajout de positions dans la file jusqu'� la saisie 
	 * d'une date d'ann�e nulle (date non empil�e) */	
	cout << "Saisir des positions jusqu'� la saisie de l'origine [0,0]\n";  
	cout << "Les positions (� l'exception de celle de l'origine)\n";
	cout << "seront ajout�es � la file de capacit� " 
		 << fPositions.c.capacite << endl;
	bool estOrigine;
	unsigned short nbSaisies =0;
	do {
		p = saisir();
		estOrigine = (p.abscisse == 0) && (p.ordonnee == 0);
		if (!estOrigine) { 
			nbSaisies++; 
			entrer(fPositions, p); 
		}
	} while (!estOrigine);
	
	cout << "Etat de la file apr�s " << nbSaisies << " position(s) entr�e(s) :";
	if (estVide(fPositions)) cout << " la file est vide" << endl;
	else cout << " la file n'est pas vide" << endl;
	
    // Sortie de file d'un el�ment si la file n'est pas vide
    cout << "Sortie de file d'un �l�ment si la file n'est pas vide" << endl;
	if (!estVide(fPositions)) sortir(fPositions);
    
    // Entr�e de file d'un nouvel �l�ment [7, 8] si la file n'est pas pleine
    cout << "Entr�e de file d'un nouvel �l�ment [7, 8] " 
             "si la file n'est pas pleine" << endl;
    p.abscisse = 7; p.ordonnee = 8;
 	if (!estPleine(fPositions)) entrer(fPositions, p);
		
	/* Afficher l'�tat de la file (par d�filage complet)  */
	cout << "D�filage complet de la file : " << endl;
	while (!estVide(fPositions)) {
		cout << "El�ment sorti de file : ";
		/* Afficher la t�te de file */
		afficher(tete(fPositions)); cout << endl;
		/* Sortir l'�l�ment en t�te de file */
		sortir(fPositions);
	}
	cout << "Fin de d�filage, la file est vide";
	
	detruire(fPositions);
	
	return 0;
}
