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
void afficherMenu();
void ajouterJoueur();
void ajouterPlusieursJoueurs();
void afficherTousJoueurs();
void trierParNom();
void trierParAge();
void afficherParPoste();
void modifierJoueur();
void supprimerJoueur();
void rechercherJoueur();

void bubbleSortNom(Joueur arr[], int n);
void bubbleSortAge(Joueur arr[], int n);

int main() {
    int choix;
    
    printf("=== BIENVENUE DANS LA GESTION D'EQUIPE DE FOOTBALL ===\n\n");
    
    do {
        afficherMenu();
        printf("Votre choix: ");
        scanf("%d", &choix);
         switch(choix) {
            case 1:
                ajouterJoueur();
                break;
            case 2:
                ajouterPlusieursJoueurs();
                break;
            case 3:
                afficherTousJoueurs();
                break;
            case 4:
                trierParNom();
                break;
            case 5:
                trierParAge();
                break;
            case 6:
                afficherParPoste();
                break;
            case 7:
                modifierJoueur();
                break;
            case 8:
                supprimerJoueur();
                break;
            case 9:
                rechercherJoueur();
                break;
                break;
            case 0:
                printf("\nMerci d'avoir utilisé notre système de gestion!\n");
                printf("Au revoir et bonne continuation!\n");
                break;
            default:
                printf("\nChoix invalide! Veuillez réessayer.\n\n");
        }
        
        if(choix != 0) {
            printf("\nAppuyez sur Entrée pour continuer");
            getchar();
        }
        
    } while(choix != 0);
    
    return 0;
}

