# Structures de Données et Algorithmique

IUT Paris Descartes 2017 - 2018
Maud GELLEE Groupe
Arsène LAPOSTOLET

Mémoire de Projet

## Introduction

Internet se fonde sur le transfert de paquets. C’est pourquoi quand on trans-
met des données en réseau, on divise ces données en paquets-réseau pour rendre
leur transfert possible. A là réception des paquets, il est nécessaire de disposer
d’un outil de messagerie pour réorganiser les données afin des les rendre intelli-
gibles pour l’utilisateur.

**Problématique :**

Programmer une application de gestion de messagerie.

**Rôle fonctionnel du projet :**

L’objectif de ce projet est de programmer un logiciel dont la fonction est de
lire des paquets-réseau dans un fichier texte. Il doit ensuite rassembler les don-
nées contenues dans ces paquets et les classer pour les rendre compréhensibles
par l’utilisateur. Ces données sont également rangées dans des fichiers texte en
fonction de leur destinataire par souci d’organisation. On rapporte les activités du
logiciel dans un fichier texte appelé log afin de voir ce qui a été effectué. Le logi-
ciel doit également gérer la perte de paquets. C’est-à-dire que si tous les paquets
constituant un message n’ont pas été recueillis via le réseau, on supprime ce mes-
sage.

**Les entrées et sorties :**

Les entrées du programme correspondent à un fichier texte qui contient les
paquet-réseau constitués de leurs identifiants et des données qu’ils contiennent.

Le programme fait l’acquisition de ces informations par le biais d’un flot d’en-
trée de type _std::ifstream._ Les flots sont issus de la bibliothèque _<ifstream>._ On
va ensuite ouvrir ce fichier grâce à la méthode _.open._ Nous avons donc spécifié et


codé des fonctions de lecture pour ranger les données ainsi lues dans les compo-
sants de notre application. Le prototype de ces fonctions est par exemple pour un
Paquet Réseau : _void lire(std::istream& is, PaquetReseau& packRes);_.

Pour ce qui est des sorties nous avons, pour les mêmes composants, codés des
fonctions d’affichage pour envoyer les contenus désirés dans un flot de sortie. Le
prototype de ces fonctions est, par exemple, pour un Paquet Réseau : _void afficher
(std::ostream& os, PaquetReseau& packRes);_. Nous ouvrons ensuite les flots de
sortie dont nous avons besoin. _std::cout_ pour la trace écran, _Mailbox_ pour écrire
dans les Mailbox, et _log_ pour écrire dans le fichier log.


## Graphe de dépendance fonctionnelle



Le projet a été mené sous forme de sprints définis par le génie logiciel. Un
sprint est défini par une spécification, un jeu de données de test (inSp#) ainsi
que des résultats attendus (OutSp#).
Un test permet de valider un objectif. Il utilise donc le jeu de données de
test (JDT) et le résultat précis. Nous avons donc utilisé la redirection de flux
d’entrée pour tester rapidement et efficacement nos programmes afin de vali-
der nos sprints.
Nous avons ainsi créé un dossier contenant les fichiers requis :
Utilisation de l’invite de commande pour la redirection :

```
Microsoft Windows [version 10.0.16299.19]
(c) 2017 Microsoft Corporation. Tous droits réservés.
C:\Users\arsen>cd Onedrive
C:\Users\arsen\OneDrive>cd Documents
C:\Users\arsen\OneDrive\Documents>cd "TEST_SDA"
C:\Users\arsen\OneDrive\Documents\TEST_SDA">"sprint 5.exe" <inSp5.txt>
run.txt
C:\Users\arsen\OneDrive\Documents\TEST_SDA">
On crée ainsi un fichier run.txt qui contient les sorties de notre programme.
```
##  Organisation des tests


Il s’agit ensuite de comparer ce fichier de sorties run.txt avec le fichier des sor-
ties attendues OutSp#.txt. Pour cela on utilise un outil fourni par les profes-
seurs, diff.jar :

Ce programme nous montre ainsi les différences entre le fichier de sortie
produit par notre programme et le fichier de sortie attendu. Si des différences
apparaissent, il convient de revoir le programme, sinon, il est déclaré 0-défaut,
et on passe à la suite.


## Bilan de validation des tests

Pour le bilan de la validation de tests, notre projet valide les six sprints.

Pour le premier sprint, il faut créer les composants BlocData, Identifica-
teurMessage _et PaquetReseau_. Il faut également coder leurs fonctions de lecture et
d’affichage. Les fonctions de lecture utilisent la lecture mot à mot pour Identifica-
teurMessage et de la lecture mot à mot combinée à un appel de la mé-
thode. _getline_. Pour PaquetReseau, on a un appel des fonctions de lecture de
BlocData et IdentificateurMessage. Il est ensuite nécessaire dans le main de faire
une boucle qui va lire le fichier pour stocker ses données dans les composants
pour ensuite afficher les composants. Le sprint permet de tester si nos flots fonc-
tionnent correctement. La comparaison des fichiers obtenus par redirection nous a
montré que des espaces en début de ligne manquaient. Nous avons donc créé la
fonction _NettoyerLigne_ , donnée par notre professeur, qui agit come un _ws_ en lais-
sant l’espace en début de ligne. Nous sommes ensuite passés au sprint de niveau
supérieur.

Pour le deuxième sprint, il faut organiser les données en mémoire. C’est pour-
quoi on utilise le composant Liste, reposant sur un conteneur en mémoire dyna-
mique des composants tous deux fournis par l’équipe pédagogique. Il faut égale-
ment créer les composants Messagerie, MessageEnCours et spécialiser le compo-
sant Item en MessageEnCours. Nous avons codé pour MessageEnCours des fonc-
tions _initialiser_ et _detruire_ pour manipuler ce composant. Il faut également coder
la fonction _estEgal_ dans IdentificateurMessage qui permet de comparer deux
IdentificateurMessage. Enfin, dans le composant de Messagerie, nous avons codé
la fonction _TraiterPaquetReseau_ qui permet de comparer les PaquetReseau et de
les ranger dans la liste sous forme de MessageEnCours. Dans le main, on ajoute
l’appel de _TraiterPaquetReseau_ dans la boucle de lecture. On fait ensuite une
boucle d’affichage car ce qui est demandé ici c’est les IdentificateursMessage. La
comparaison des fichiers obtenus par redirection nous a permis de déclarer
cesprint comme 0-défaut et de passer au sprint de niveau supérieur.


Pour le troisième sprint, il faut stocker les blocs de données en mémoire, pour
pouvoir les ranger par identifiant. Nous avons donc implémenté le composant de
file fourni par l’équipe pédagogique. Il faut aussi spécifier le type _Itemf_ en _BlocD_
ainsi que modifier la fonction _TraiterPaquetReseau_ et la structure _MessageEn-
Cours._ Nous avons envisagé deux cas : celui où l’identifiant est encore inconnu et
celui où on a déjà reçu un paquet de ce message. Etant donné que nous ne devions
pas encore trier les blocs de données en fonction de leur place dans le message, il
nous a suffit de les implémenter en mémoire grâce à la structure _MessageEn-
Cours_. En effet, la file se trouve dans cette dernière. La comparaison des fichiers
obtenus par redirection nous a permis de déclarer ce sprint comme 0-
défaut et de passer au sprint de niveau supérieur.

Le quatrième sprint n’a rien à voir avec les précédents. Il consiste à modifier
la fonction _ecrire_ du composants de file fourni par l’équipe pédagogique. Désor-
mais la fonction _ecrire_ devait se rapprocher de la fonction _inserer_ d’un composant
de liste. En effet, à chaque fois que la fonction _entrer_ est appelée on parcourt toute
la file afin de comparer le critère de l’ _item_ à insérer avec celui des _item_ déjà exis-
tants. Pour cela on utilise la fonction _EnOrdre_ qui compare des _int_. Ainsi, la file
obtenu est une file à priorité, c’est-à-dire que les _item_ qu’elle stocke sont stockés
par ordre de priorité (ordre déterminé par le critère de la fonction _EnOrdre_ ). La
comparaison des fichiers obtenus par redirection nous a permis de déclarer c e
sprint comme 0-défaut et de passer au sprint de niveau supérieur.

Pour le cinquième sprint, il faut désormais que les blocs de données soient
rangés en fonction de leur numéro de bloc. Nous utilisons le composant de file à
priorité développé dans le quatrième sprint à la place du composant file. Nous
choisissons le numéro de bloc comme critère dans la fonction _EnOrdre._ Ainsi nous
obtenons les messages originaux. La comparaison des fichiers obtenus par redi-
rection nous a permis de déclarer ce sprint comme 0-défaut et de passer au sprint de niveau supérieur.

Pour le sixième sprint, il faut créer les fichiers de Mailbox et le fichier log.
Pour chaque action telle que la réception d’un nouveau message, suppression d’un
message, nous avons dû réutiliser les flots d’entrée-sortie pour créer un fichier log
ainsi que plusieurs fichiers Mailbox qui correspondent à la messagerie de chaque
destinataire. Nous avons donc modifié la fonction _TraiterPaquetReseau_ à cet effet.
De plus, nous devons désormais prendre en compte la perte de paquets réseau.
On ne doit afficher le message que lorsque tous les blocs de données d’un message
ont été reçus dans les temps. Nous nous sommes heurtés à trois difficultés ma-
jeures. La première concernait la suppression de paquets réseau. Au début, nous
avions pensé que pour chaque paquet réseau reçu, nous devions vérifier si son nu-
méro de paquet réseau était inférieur ou non à _10 + lastPRecu._ Cette technique
fonctionnait parfaitement. Cependant, lorsque nous avons commencé à remplir le
fichier log, nous nous sommes rendus compte que cette opération était effectuée
trop tard par notre programme par rapport au log attendu. Nous avons donc,
après comparaison, dû changer la fonction. Ainsi, à chaque paquet réseau, la fonc-
tion _TraiterPaquetReseau_ vérifie si pour tous les messages en cours, le numéro du
_lastPRecu_ est inférieur ou non à 10 + le numéro du paquet actuel. Notre deuxième
problème portait sur la création des Mailbox. En effet, nous avions deux manières
de procéder : soit en créant un fichier Mailbox dès qu’un nouveau destinataire
était repéré, soit en créant la Mailbox lorsque tout le message avait été reçu. La
première solution nous permettait d’écrire correctement le titre de cette Mailbox,
sans doublons (exemple : Mailbox all qui recevait deux messages différents). Mais
nous devions alors supprimer les Mailbox, dans lesquelles des messages étaient
perdus et se retrouvaient donc vides en fin de programme (exemple : Mailbox
grp9a12). Or, nous ne sommes pas parvenu à supprimer un fichier, malgré nos es-
sais avec la fonction _remove()_. Nous avons donc opté pour la deuxième solution,
mais nous devions nous assurer que le titre n’était pas écrit deux fois en cas de
réception de deux messages différents pour un même destinataire. Après
quelques essais infructueux, nous sommes finalement parvenus grâce à la


fonction _getline()_ à vérifier si nous avions déjà écrit le titre dans un fichier. Une
fois ces deux problèmes résolus, notre sprint six était pratiquement 0-défaut, mis
à part quelques problèmes d’espaces en trop pour les blocs de données, problème
que nous n’avons pas réussi à résoudre.


##  Bilan du Projet

Ce projet collaboratif en programmation nous a permis de découvrir le lan-
gage C++, ses possibilités, mais aussi ses aspects difficiles à appréhender. En ef-
fet, ce projet a constitué pour nous une introduction aux mécaniques des flots
d’entrée-sortie, mais aussi à la compilation séparée, qui permet une meilleure or-
ganisation et un repérage plus intuitif dans le projet, augmentant ainsi la pro-
ductivité. Cela nous a aidé non seulement à parfaire notre maîtrise des outils de
programmation impérative mais aussi à intégrer la rigueur de la documentation
formatée, afin de faciliter l’implémentation de mise à jour ainsi que les modifica-
tions ultérieures. Tout au long de ce projet, nous avons encore une fois ressenti en
nous l’âme du développeur. En effet, le fait de créer un tel logiciel fourni un senti-
ment d’accomplissement très agréable. Nous nous sommes sentis encore plus
proche du programmeur qui fait tout son possible pour remplir son contrat.
Chaque difficulté surmontée par la réflexion nous à motivé à avancer plus encore
et à persévérer pour parachever notre ouvrage. Quand on développe ces projets,
on se sent programmeur, et c’est vraiment une expérience unique.

Enfin, l’aspect collaboratif de ce projet fait partie de ses points forts. En effet,
la motivation mutuelle est un moteur si puissant qu’il permet de surmonter tout
type de désespoir. De plus, la puissance de deux esprits focalisés sur le même ob-
jectif, communicant sur un problème est une des formes les plus efficaces de ré-
flexion. Chacun comblant les faiblesses de l’autre, nous avons pu nous tirer mu-
tuellement vers le haut. Ayant déjà l’expérience du travail en commun, nous
avons renforcé notre niveau de collaboration et cela nous a permis d’avancer en-
core plus vite malgré les difficultés, chacun connaissant les spécificités de l’autre.
Encore une fois, cette expérience nous permet d’affirmer que la collaboration sur
un tel projet est la forme la plus productive de travail.


##  Annexes

Annexe 1 : Jeu de données de test (inSp6.txt), sorties attendues (MailboxAll.txt,
Mailboxgr1a4.txt, Mailboxgr5a8.txt, traceecran.txt, log.txt) et sorties
((MailboxAll.txt, Mailboxgr1a4.txt, Mailboxgr5a8.txt, traceecran.txt, log.txt) pour
le sprint 6.


## 1 Detection de nouveau message caraty gr9a12 26/11/17 14:16:37

Commentez vos source

## 2 Detection de nouveau message caraty gr1a4 26/11/17 14:20:02

de commenter les fi

## 3 Detection de nouveau message caraty gr5a8 26/11/17 14:35:23

Programmez sans nomb
4 caraty gr1a4 26/11/17 14:20:02 0 1
Il est indispensable

## 5 Detection de fin de message caraty gr5a8 26/11/17 14:35:23

ex. 255, ".txt").
6 caraty gr1a4 26/11/17 14:20:02 0 4
uls fichiers a consu
7 caraty gr1a4 26/11/17 14:20:02 0 3
chiers d'entete : se
8 caraty gr5a8 26/11/17 14:35:23 0 3
ntes litterales, par
9 caraty gr1a4 26/11/17 14:20:02 0 5
lter pour la reutili

## 10 Detection de nouveau message caraty all 26/11/17 15:27:57

Bon courage a tous..

## 11 Detection de fin de message caraty gr1a4 26/11/17 14:20:02

sation.

## 12 Detection de nouveau message caraty all 26/11/17 15:25:41

Bon travail...
13 caraty gr5a8 26/11/17 14:35:23 0 2
res magiques (consta

## 14 Detection de nouveau message caraty gr9a12 26/11/17 14:16:37

s.

## 15 Detection de fin de message caraty all 26/11/17 15:27:57

. MJC


```
Mailbox all
```
## 12 Archivage mailbox all 26/11/14 15:25:

```
Bon travail...
```
## 15 Archivage mailbox all 26/11/14 15:27:

```
Bon courage a tous... MJC
```
Mailbox gr1a

## 11 Archivage mailbox gr1a4 26/11/14 14:20:

Il est indispensable de commenter les fichiers d'entete : seuls fichiers a consulter pour la reutilisation.

```
Mailbox gr5a
```
## 13 Archivage mailbox gr5a8 26/11/14 14:35:

```
Programmez sans nombres magiques (constantes litterales, par ex. 255, ".txt").
```
```
caraty gr1a4 26/11/14 14:20:
Il est indispensable de commenter les fichiers d'entete : seuls fichiers a consulter pour la reutilisation.
```
```
caraty all 26/11/14 15:25:
Bon travail...
```
```
caraty gr5a8 26/11/14 14:35:
Programmez sans nombres magiques (constantes litterales, par ex. 255, ".txt").
```
```
caraty all 26/11/14 15:27:
Bon courage a tous... MJC
```


```
Mailbox all
```
## 12 Archivage mailbox all 26/11/17 15:25:

```
Bon travail...
```
## 15 Archivage mailbox all 26/11/17 15:27:

```
Bon courage a tous... MJC
```
Mailbox gr1a

## 11 Archivage mailbox gr1a4 26/11/17 14:20:

Il est indispensable de commenter les fichiers d'entete : seuls fichiers a consulter pour la reutilisation.

```
Mailbox gr5a
```
## 13 Archivage mailbox gr5a8 26/11/17 14:35:

```
Programmez sans nombres magiques (constantes litterales, par ex. 255, ".txt").
```
```
caraty gr1a4 26/11/17 14:20:
Il est indispensable de commenter les fichiers d'entete : seuls fichiers a consulter pour la reutilisation.
```
```
caraty all 26/11/17 15:25:
Bon travail...
```
```
caraty gr5a8 26/11/17 14:35:
Programmez sans nombres magiques (constantes litterales, par ex. 255, ".txt").
```
```
caraty all 26/11/17 15:27:
Bon courage a tous... MJC
```
