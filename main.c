#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void viderBuffer();
int numeroMaillotExiste(int numero);
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
            case 0:
                printf("\nMerci d'avoir utilisé notre système de gestion!\n");
                printf("Au revoir et bonne continuation! \n");
                break;
            default:
                printf("\n  Choix invalide! Veuillez réessayer.\n\n");
        }
        
        if(choix != 0) {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
        }
        
    } while(choix != 0);
    
    return 0;
}
void afficherMenu() {
    printf("       MENU PRINCIPAL - FOOTBALL       \n");
    printf("   1. Ajouter un joueur                   \n");
    printf("   2. Ajouter plusieurs joueurs          \n");
    printf("   3. Afficher tous les joueurs          \n");
    printf("   4. Trier par nom (alphabétique)       \n");
    printf("   5. Trier par âge                      \n");
    printf("   6. Afficher par poste                 \n");
    printf("   7. Modifier un joueur                 \n");
    printf("   8. Supprimer un joueur                \n");
    printf("   9. Rechercher un joueur               \n");
    printf("   10. Afficher les statistiques         \n");
    printf("   0. Quitter                            \n");

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
viderBuffer();
    fgets(nouveauJoueur.nom, MAX_NAME_LENGTH, stdin);
    nouveauJoueur.nom[strcspn(nouveauJoueur.nom, "\n")] = 0; 
    
    printf("Prenom: ");
    fgets(nouveauJoueur.prenom, MAX_NAME_LENGTH, stdin);
    nouveauJoueur.prenom[strcspn(nouveauJoueur.prenom, "\n")] = 0;
    do {
        printf("Numero de maillot (1-99): ");
        scanf("%d", &nouveauJoueur.numeroMaillot);
        if(numeroMaillotExiste(nouveauJoueur.numeroMaillot)) {
           
            printf(" Ce numéro est déjà pris! Choisissez un autre.\n");
       viderBuffer();
       continue;
       }
        if (nouveauJoueur.numeroMaillot < 1 || nouveauJoueur.numeroMaillot > 99) {
            printf(" Numéro invalide! Il doit être entre 1 et 99.\n");
            continue;
        }
        if (numeroMaillotExiste(nouveauJoueur.numeroMaillot)) {
            printf(" Ce numéro est déjà pris! Choisissez un autre.\n");
            continue;
        }
        break; 
    } while(1);
     viderBuffer();
    
    printf("Poste (Gardien/Defenseur/Milieu/Attaquant): ");
    fgets(nouveauJoueur.poste, MAX_NAME_LENGTH, stdin);
    nouveauJoueur.poste[strcspn(nouveauJoueur.poste, "\n")] = 0;
    
    printf("Age: ");
    scanf("%d", &nouveauJoueur.age);
    
    printf("Nombre de buts: ");
    scanf("%d", &nouveauJoueur.buts);
    viderBuffer();
    equipe[nombreJoueurs] = nouveauJoueur;
    nombreJoueurs++;
    
    printf("\n Joueur ajouté avec succès! ID: %d\n", nouveauJoueur.id);
}

void ajouterPlusieursJoueurs() {
    int nombre;
    printf("\nCombien de joueurs voulez-vous ajouter? ");
    scanf("%d", &nombre);
    
    if(nombreJoueurs + nombre > MAX_PLAYERS) {
        printf(" Impossible d'ajouter %d joueurs. Places disponibles: %d\n", 
               nombre, MAX_PLAYERS - nombreJoueurs);
        return;
    }
    
    for(int i = 0; i < nombre; i++) {
        printf("\n--- Joueur %d/%d ---\n", i+1, nombre);
        ajouterJoueur();
    }
}
void afficherTousJoueurs() {
    if(nombreJoueurs == 0) {
        printf("\n Aucun joueur dans l'équipe!\n");
        return;
    }
    
    printf("\n=== LISTE COMPLÈTE DE L'ÉQUIPE (%d joueurs) ===\n", nombreJoueurs);
    for(int i = 0; i < nombreJoueurs; i++) {
        char nomComplet[101];
        sprintf(nomComplet, "%s %s", equipe[i].nom, equipe[i].prenom);
        printf("│ %-3d │ %-19s │ %-6d │ %-11s │ %-3d │ %-4d │\n",
               equipe[i].id,
               nomComplet,
               equipe[i].numeroMaillot,
               equipe[i].poste,
               equipe[i].age,
               equipe[i].buts);
    }
}
void bubbleSortNom(Joueur arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(strcmp(arr[j].nom, arr[j+1].nom) > 0) {
                Joueur temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortAge(Joueur arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j].age > arr[j+1].age) {
                Joueur temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void trierParNom() {
    if(nombreJoueurs == 0) {
        printf("\n Aucun joueur à trier!\n");
        return;
    }
    
    Joueur copie[MAX_PLAYERS];
    for(int i = 0; i < nombreJoueurs; i++) {
        copie[i] = equipe[i];
    }
    
    bubbleSortNom(copie, nombreJoueurs);
    
    printf("\n=== JOUEURS TRIÉS PAR NOM (A-Z) ===\n");
    for(int i = 0; i < nombreJoueurs; i++) {
        printf("%d. %s %s - %s (%d ans, %d buts)\n", 
               i+1, copie[i].nom, copie[i].prenom, copie[i].poste, copie[i].age, copie[i].buts);
    }
}

void trierParAge() {
    if(nombreJoueurs == 0) {
        printf("\n Aucun joueur à trier!\n");
        return;
    }
    
    Joueur copie[MAX_PLAYERS];
    for(int i = 0; i < nombreJoueurs; i++) {
        copie[i] = equipe[i];
    }
    
    bubbleSortAge(copie, nombreJoueurs);
    
    printf("\n=== JOUEURS TRIÉS PAR ÂGE (croissant) ===\n");
    for(int i = 0; i < nombreJoueurs; i++) {
        printf("%d. %s %s - %d ans (%s, %d buts)\n", 
               i+1, copie[i].nom, copie[i].prenom, copie[i].age, copie[i].poste, copie[i].buts);
    }
}

void afficherParPoste() {
    if(nombreJoueurs == 0) {
        printf("\n Aucun joueur dans l'équipe!\n");
        return;
    }
    
    char poste[MAX_NAME_LENGTH];
    printf("Entrez le poste à rechercher: ");
    fgets(poste, MAX_NAME_LENGTH, stdin);
    poste[strcspn(poste, "\n")] = 0;
    
    printf("\n=== JOUEURS AU POSTE: %s ===\n", poste);
    int trouve = 0;
    
    for(int i = 0; i < nombreJoueurs; i++) {
        if(strcasecmp(equipe[i].poste, poste) == 0) {
            printf("• %s %s (ID: %d, Maillot: %d, %d ans, %d buts)\n",
                   equipe[i].nom, equipe[i].prenom, equipe[i].id, 
                   equipe[i].numeroMaillot, equipe[i].age, equipe[i].buts);
            trouve = 1;
        }
    }
    
    if(!trouve) {
        printf(" Aucun joueur trouvé à ce poste.\n");
    }
}
void modifierJoueur() {
    if(nombreJoueurs == 0) {
        printf("\n Aucun joueur à modifier!\n");
        return;
    }
    
    int id, choix;
    printf("Entrez l'ID du joueur à modifier: ");
    scanf("%d", &id);
     viderBuffer();
    int index = -1;
    for(int i = 0; i < nombreJoueurs; i++) {
        if(equipe[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("Joueur non trouvé!\n");
        return;
    }
    
    printf("\nJoueur trouvé: %s %s\n", equipe[index].nom, equipe[index].prenom);
    printf("1. Modifier le poste\n2. Modifier l'âge\n3. Modifier les buts\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
     viderBuffer();
 switch(choix) {
        case 1:
            printf("Nouveau poste: ");
            fgets(equipe[index].poste, MAX_NAME_LENGTH, stdin);
            equipe[index].poste[strcspn(equipe[index].poste, "\n")] = 0;
            break;
        case 2:
            printf("Nouvel âge: ");
            scanf("%d", &equipe[index].age);
            break;
        case 3:
            printf("Nouveau nombre de buts: ");
            scanf("%d", &equipe[index].buts);
            break;
        default:
            printf(" Choix invalide!\n");
            return;
    }
    
    printf(" Joueur modifié avec succès!\n");
}

void supprimerJoueur() {
    if(nombreJoueurs == 0) {
        printf("\n Aucun joueur à supprimer!\n");
        return;
    }
    
    int id;
    printf("Entrez l'ID du joueur à supprimer: ");
    scanf("%d", &id);
    
    int index = -1;
    for(int i = 0; i < nombreJoueurs; i++) {
        if(equipe[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("Joueur non trouvé!\n");
        return;
    }
    
    printf("Voulez-vous vraiment supprimer %s %s? (o/n): ", 
           equipe[index].nom, equipe[index].prenom);
   viderBuffer();
           char confirmation = getchar();
    
    if(confirmation == 'o' || confirmation == 'O') {
        for(int i = index; i < nombreJoueurs - 1; i++) {
            equipe[i] = equipe[i + 1];
        }
        nombreJoueurs--;
        printf(" Joueur supprimé avec succès!\n");
    } else {
        printf(" Suppression annulée.\n");
    }
}

void rechercherJoueur() {
    if(nombreJoueurs == 0) {
        printf("\n Aucun joueur dans l'équipe!\n");
        return;
    }
    
    int choix;
    printf("1. Rechercher par ID\n2. Rechercher par nom\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    viderBuffer();
    if(choix == 1) {
        int id;
        printf("Entrez l'ID: ");
        scanf("%d", &id);
        
        for(int i = 0; i < nombreJoueurs; i++) {
            if(equipe[i].id == id) {
                printf("\n Joueur trouvé:\n");
                printf("ID: %d | %s %s | Maillot: %d | %s | %d ans | %d buts\n",
                       equipe[i].id, equipe[i].nom, equipe[i].prenom,
                       equipe[i].numeroMaillot, equipe[i].poste, equipe[i].age,
                       equipe[i].buts);
                return;
            }
        }
        printf("Aucun joueur avec cet ID.\n");
        
    } else if(choix == 2) {
        char nom[MAX_NAME_LENGTH];
        printf("Entrez le nom: ");
        fgets(nom, MAX_NAME_LENGTH, stdin);
        nom[strcspn(nom, "\n")] = 0;
        
    }
}
void afficherstatistique(){
    if(nombreJoueurs == 0 ){
        printf("aucun statistique disponible");
        return;

    }
    
    printf("***STATISTIQUES DE L'EQUIPE\n");
    printf("Nombre total des joueurs :%d\n", nombreJoueurs);
    int sommeAge = 0;
    for(int i = 0; i<nombreJoueurs ; i++){
        sommeAge += equipe[i].age;
    }
    float ageMoyen = (float)sommeAge / nombreJoueurs;
    printf("AGE moyen: %1.f ans\n", ageMoyen);
    int seuilButs;
    printf("\nEntrez le seuil de buts pour la recherche: ");
    scanf("%d", &seuilButs);
    printf(" Joueurs avec plus de %d buts:\n", seuilButs);
    
    int buteursCompetents = 0;
    for(int i = 0; i < nombreJoueurs; i++) {
        if(equipe[i].buts > seuilButs) {
            printf(" %s %s: %d buts\n", equipe[i].nom, equipe[i].prenom, equipe[i].buts);
            buteursCompetents++;
        }
    }
    if(buteursCompetents == 0) {
        printf("  Aucun joueur trouvé.\n");
    }
int maxButs = -1, indexMeilleur = -1;
    for(int i = 0; i < nombreJoueurs; i++) {
        if(equipe[i].buts > maxButs) {
            maxButs = equipe[i].buts;
            indexMeilleur = i;
        }
    }
    if(indexMeilleur != -1) {
        printf(" Meilleur buteur: %s %s avec %d buts\n", 
               equipe[indexMeilleur].nom, equipe[indexMeilleur].prenom, maxButs);
    }
     int minAge = 999, maxAge = -1, indexJeune = -1, indexAge = -1;
    for(int i = 0; i < nombreJoueurs; i++) {
        if(equipe[i].age < minAge) {
            minAge = equipe[i].age;
            indexJeune = i;
        }
        if(equipe[i].age > maxAge){
            maxAge = equipe[i].age;
             indexAge = i;
        }
    }
     printf("Plus jeune: %s %s (%d ans)\n", 
           equipe[indexJeune].nom, equipe[indexJeune].prenom, minAge);
    printf("Plus âgé: %s %s (%d ans)\n", 
           equipe[indexAge].nom, equipe[indexAge].prenom, maxAge);
}
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int numeroMaillotExiste(int numero) {
    for (int i = 0; i < nombreJoueurs; i++) {
        if (equipe[i].numeroMaillot == numero) {
            return 1;
        }
    }
    return 0;
}

