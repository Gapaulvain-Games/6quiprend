#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "affichage.h"

#define N 16

#define ROUGE "\x1B[0;31m"
#define JAUNE "\x1B[33m"
#define CYAN   "\x1B[36m"
#define BLANC "\e[0;97m"
#define RESET "\x1B[0m"



void nombreFormatte(int nb) {
    if (nb<10){
		printf("%d  ",nb);
	} else if (nb<100){
		printf("%d ",nb);
	} else {
        printf("%d",nb);
    }
}


void affCarteLigne1(carte c) {  
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(JAUNE"┏━━━━━━━━┓"RESET);
    } else {
        printf("┏━━━━━━━━┓");
    }
}


void affCarteLigne2(carte c) {
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(JAUNE"┃ ");
        nombreFormatte(c.numero);
        printf("    ┃"RESET);
    } else {
        printf("┃ ");
        nombreFormatte(c.numero);
        printf("    ┃");
    }
}


void affCarteLigne3(carte c) {
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(JAUNE"┃        ┃"RESET);
    } 
    else {
        printf("┃        ┃");
    }
}


void affCarteLigne4(carte c) {
    affCarteLigne3(c);
}


void affCarteLigne5(carte c) {
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(JAUNE);
    } 
    switch (c.tdb) {
        case 1:
        printf("┃   ✱    ┃");
        break;

        case 2:
        printf("┃  ✱ ✱   ┃");
        break;

        case 3:
        printf("┃ ✱ ✱ ✱  ┃");
        break;

        case 5:
        printf("┃  ✱ ✱   ┃");
        break;

        case 7:
        printf("┃ ✱ ✱ ✱  ┃");
        break;
    }
            
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(RESET);
    }
}


void affCarteLigne6(carte c) {
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(JAUNE);
    } 
    switch (c.tdb) {
        case 7:
        printf("┃✱ ✱ ✱ ✱ ┃");
        break;

        case 5:
        printf("┃ ✱ ✱ ✱  ┃");
        break;

        default:
        printf("┃        ┃");
    }   
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(RESET);
    } 
}

void affCarteLigne7Last(carte c) {
    if (c.estRecente) { // Vérifie si la carte est récente et l'affiche en jaune si c'est le cas
        printf(JAUNE"┗━━━━━━━━┛"RESET);
    } else {
        printf("┗━━━━━━━━┛");
    }
}


void affLigneCarte(int ligne,carte* tabCartes, int taille) {
    switch (ligne) {
        case 1:
        for (int i=0; i<taille;i++) {
        affCarteLigne1(tabCartes[i]);
        }
        break;

        case 2:
        for (int i=0; i<taille;i++) {
        affCarteLigne2(tabCartes[i]);
        }
        break;

        case 3:
        for (int i=0; i<taille;i++) {
        affCarteLigne3(tabCartes[i]);
        }
        break;

        case 4:
        for (int i=0; i<taille;i++) {
        affCarteLigne4(tabCartes[i]);
        }
        break;

        case 5:
        for (int i=0; i<taille;i++) {
        affCarteLigne5(tabCartes[i]);
        }
        break;

        case 6:
        for (int i=0; i<taille;i++) {
        affCarteLigne6(tabCartes[i]);
        }
        break;

        case 7:
        for (int i=0; i<taille;i++) {
        affCarteLigne7Last(tabCartes[i]);
        tabCartes[i].estRecente = 0; // Dés que la carte est affiché, elle n'est plus récente
        }
        break;
    }
}


void affVideLigne(int ligne,int taille) {
    if (taille ==5) {
        printf(ROUGE);
    }
    switch (ligne) {
        case 1:
        printf("┏ ━ ━━ ━ ┓");
        break;

        case 2:
        printf("┃        ┃");
        break;

        case 3:
        printf("          ");
        break;

        case 4:
        printf("┃        ┃");
        break;

        case 5:
        printf("          ");
        break;

        case 6:
        printf("┃        ┃");

        break;

        case 7:
        printf("┗ ━ ━━ ━ ┛");
        break;

    }
    if (taille ==5) {
        printf(RESET);
    }
}


void actualiserScoreboard(scoreboard* scboard) {
    scboard->compteurAffichage = -3;
}


void afficherScoreboard(scoreboard* scboard) {
    printf("               "); // Espace qui permet de s'espacer de la table
    if (scboard->compteurAffichage < scboard->nombreJoueurs) {
    switch (scboard->compteurAffichage) {


        case -3:
        printf("┇ \e[1mScoreboard\e[m    "); // Scoreboard est écrit en GRAS
        break;

        case -2:
        printf("┇ La partie se joue en "ROUGE"%d"RESET" points",scboard->scoremax);
        break;

        case -1:
        printf("┇");
        break;

        default:
        if (scboard->infoJoueurs[scboard->compteurAffichage].estRobot) {
            printf("┇    "CYAN"%s"RESET" : %d TdB", scboard->infoJoueurs[scboard->compteurAffichage].pseudo, scboard->infoJoueurs[scboard->compteurAffichage].score);
        } else {
            printf("┇    "BLANC"%s"RESET" : %d TdB", scboard->infoJoueurs[scboard->compteurAffichage].pseudo, scboard->infoJoueurs[scboard->compteurAffichage].score);
        }
        
    }
        scboard->compteurAffichage = scboard->compteurAffichage +1;
    }

}


void affDeckTable(carte* tabCartes, int taille, scoreboard* scboard) {
    for (int i=1;i<=7;i++) {
        affLigneCarte(i,tabCartes,taille);
        affVideLigne(i,taille);

        // Print du vide pour que le scoreboard soit fixe
        for (int j=taille+1; j< 6;j++) {
            printf("          ");
        }
        // Affichage du scoreboard à gauche des cartes
        afficherScoreboard(scboard);
        printf("\n");
    }
}


void affDeckJoueur(carte* tabCartes, int taille) {
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    // Affichage des cartes
    for (int i=1;i<=7;i++) {
        printf("  ");
        affLigneCarte(i,tabCartes,taille);
        printf("  ");
        printf("\n");
    }
    printf("      ");
    // Affichage des emplacements de cartes en bas 1 2 3 4 5 6 7 8 9 10
    for (int i=1 ; i<=taille; i++) {
        printf(CYAN"%d         "RESET,i); // Couleur cyan
    }
    printf(" ");
    printf("\n╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}


void afficherTable(table table, scoreboard* scboard) {
    actualiserScoreboard(scboard); // Actualise la valeur du scoreboard
    for (int i=0; i<4; i++) {
        affDeckTable(table.tabDecks[i],table.tabTailleDecks[i],scboard);
    }
}


void txtFormatte(char* strFusion,char* texte, char* espace) {
    int nombreDeCaracteres = strlen(strFusion) - strlen(texte);
    int nbCaracGauche = nombreDeCaracteres/2;
    int nbCaracDroite = nombreDeCaracteres/2 + nombreDeCaracteres%2;
    for (int i=0; i<nbCaracGauche;i++){
		printf("%s",espace);
    }
    printf("%s",texte);
    for (int i=0; i<=nbCaracDroite;i++){
		printf("%s",espace);
    }
}

void afficherBox(char* str) {
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                                                                                                        \n");
    printf("                                                                                                        \n");
    printf("                                                                                                        \n");
   txtFormatte("                                                                                                      ",str," ");
    printf("\n");
    printf("                                                                                                        \n");
    printf("                                                                                                        \n");
    printf("                                                                                                        \n");
    printf("                                                                                                        \n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}


void affichageScoreFinDeManche(scoreboard* scboard, int nombreJoueurs){
    actualiserScoreboard(scboard);
    printf("╔═══════════════════════╗\n");
    printf("       \e[1mScoreboard\e[m    \n");
    printf("╚═══════════════════════╝\n");
    for(int i=0;i<nombreJoueurs;i++){
        scboard->compteurAffichage = i;
        if (i!=0) printf("┇");
        printf("\n┇    %s : %d TdB\n", scboard->infoJoueurs[i].pseudo, scboard->infoJoueurs[i].score);
    }
}


void affichageScoreFinDePartie(scoreboard* scboard, int nombreJoueurs){
    actualiserScoreboard(scboard);
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("                                          \e[1mScores finaux \e[m    \n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    switch (nombreJoueurs){
        case 2 :
            scboard->compteurAffichage = 0;

            printf("\n                              │      1ère place : "JAUNE"%s"RESET" avec %d TdB\n                              │", scboard->infoJoueurs[0].pseudo, scboard->infoJoueurs[0].score);
            scboard->compteurAffichage = 1;

            printf("\n                              │      2ème place : "ROUGE"%s"RESET" avec %d TdB\n\n", scboard->infoJoueurs[1].pseudo, scboard->infoJoueurs[1].score);
        break;
        default :
            scboard->compteurAffichage = 0;

            printf("\n                              │     1ère place : "JAUNE"%s"RESET" avec %d TdB\n                              │", scboard->infoJoueurs[0].pseudo, scboard->infoJoueurs[0].score);
            for (int i=1;i<nombreJoueurs-1;i++){
                scboard->compteurAffichage = i;

                printf("\n                              │     %dème place : %s avec %d TdB\n                              │", i+1, scboard->infoJoueurs[i].pseudo, scboard->infoJoueurs[i].score);
            }
            scboard->compteurAffichage = nombreJoueurs;

            printf("\n                              │     %dème place : "ROUGE"%s"RESET" avec %d TdB\n\n",nombreJoueurs ,scboard->infoJoueurs[nombreJoueurs-1].pseudo, scboard->infoJoueurs[nombreJoueurs-1].score);
        break;
    }
}


void affTableCache () {
    for (int i=0;i<4;i++) {
        printf("╔════════╗\n");
        printf("║░░░░░░░░║ \n");
        for (int i=0;i<2;i++) {
            printf("║░░░░░░░░║\n");
        }
        printf("║░░░░░░░░║\n"); 
        printf("║░░░░░░░░║\n");
        printf("╚════════╝\n");
    }
}