#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_PLAYERS 100

typedef struct {
    int id;
    char nom[MAX_NAME_LENGTH];
    char prenom[MAX_NAME_LENGTH];
    int numeroMaillot;
    char poste[MAX_NAME_LENGTH];
    int age;
    int buts;
    char dateInscription[11]; 
    char statut[MAX_NAME_LENGTH];
} Joueur;
Joueur equipe[MAX_PLAYERS];
int nombredujoueurs = 0;
int prochainId = 1;