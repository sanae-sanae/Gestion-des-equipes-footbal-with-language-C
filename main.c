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
int nombreJoueurs = 0;
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
void afficherMenu() {
    printf("║        MENU PRINCIPAL - FOOTBALL       ║\n");
    printf("                                          \n");
    printf("  1. Ajouter un joueur                  \n");
    printf("  2. Ajouter plusieurs joueurs          \n");
    printf("  3. Afficher tous les joueurs          \n");
    printf("  4. Trier par nom (alphabétique)       \n");
    printf("  5. Trier par âge                      \n");
    printf("  6. Afficher par poste                 \n");
    printf("  7. Modifier un joueur                 \n");
    printf("  8. Supprimer un joueur                \n");
    printf("  9. Rechercher un joueur               \n");
    printf(" 10. Afficher les statistiques         \n");
    printf("  0. Quitter                            \n");
    
}
void ajouterJoueur() {
    if(nombreJoueurs >= MAX_PLAYERS) {
        printf("\n Équipe complète! Impossible d'ajouter plus de joueurs.\n");
        return;
    }
     printf("\n=== AJOUT D'UN NOUVEAU JOUEUR ===\n");
    
    Joueur nouveauJoueur;
    nouveauJoueur.id = prochainId++;
    
    printf("Nom: ");
    fgets(nouveauJoueur.nom, MAX_NAME_LENGTH, stdin);
    nouveauJoueur.nom[strcspn(nouveauJoueur.nom, "\n")] = 0;
    
    printf("Prénom: ");
    fgets(nouveauJoueur.prenom, MAX_NAME_LENGTH, stdin);
    nouveauJoueur.prenom[strcspn(nouveauJoueur.prenom, "\n")] = 0;
    do {
        printf("Numéro de maillot (1-99): ");
        scanf("%d", &nouveauJoueur.numeroMaillot);
        if(numeroMaillotExiste(nouveauJoueur.numeroMaillot)) {
            printf("Ce numéro est déjà pris! Choisissez un autre.\n");
        }
    } while(numeroMaillotExiste(nouveauJoueur.numeroMaillot));
    return 0;
}
