#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_NOM 1
#define TAILLE_PRENOM 1
#define TAILLE_EMAIL 1
#define NB_PRODUITS 5


typedef struct {
    int idClient;                  
    char nom[TAILLE_NOM];         
    char prenom[TAILLE_PRENOM];   
    char email[TAILLE_EMAIL];     
    float solde;                  
} Client;


typedef struct {
    int idProduit;
    char nom[50];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} Produit;

Produit catalogue[NB_PRODUITS] = {
    {1, "Ordinateur Portable", "Electronique", 799.0, 5, "Ordinateur performant"},
    {2, "Smartphone", "Electronique", 499.0, 10, "Ecran AMOLED"},
    {3, "Casque Audio", "Accessoires", 89.0, 15, "Casque Bluetooth"},
    {4, "Souris", "Accessoires", 25.0, 20, "Souris sans fil"},
    {5, "Clavier", "Accessoires", 45.0, 12, "Clavier mécanique"}
};




int idAuto = 1;
Client c;          
int clientCree = 0;    


void cree() {
printf("Entrez le prenom: ");
    scanf("%s", c.prenom);
    
    printf("Entrez le nom: ");
    scanf("%s", c.nom);

    c.idClient = idAuto++; 
    
    snprintf(c.email, TAILLE_EMAIL, "%s.%s@client.com", c.prenom, c.nom);
    c.solde = 0.0;
 
    printf("Profil mis a jour \n Nouvel email : %s\n", c.email);


    clientCree = 1;
}
void modifie() {
    if (!clientCree) {
        printf("Aucun profil Veuillez en creer un d'abord\n");
        return;
    }

    printf("Modifier le prenom: ");
    scanf("%s", c.prenom);
    
    printf("Modifier le nom: ");
    scanf("%s", c.nom);
    
    snprintf(c.email, TAILLE_EMAIL, "%s.%s@client.com", c.prenom, c.nom);

    printf("Profil est modifie \n Nouvel email : %s\n", c.email);
}

void consulte_profile() {
    if (!clientCree) {
        printf("Aucun profil existant \n");
        return;
    }

    printf("ID: %d\n", c.idClient);
    printf("Nom: %s\n", c.nom);
    printf("Prenom: %s\n", c.prenom);
    printf("Email: %s\n", c.email);
    printf("Solde: %.2f MAD\n", c.solde);
}

void generie() {
    if (!clientCree) {
        printf("Aucun profil existant\n");
        return;
    }

    snprintf(c.email, TAILLE_EMAIL, "%s.%s@client.com", c.prenom, c.nom);
    printf("Email genere : %s\n", c.email);
}
void consulte_solde() {
    if (!clientCree) {
        printf("Veuillez creer un profil d'abord\n");
        return;
    }

    printf("Solde actuel: %.2f MAD\n", c.solde);
}
void Depot_argent() {
    if (!clientCree) {
        printf("Veuillez creer un profil d'abord\n");
        return;
    }

    float montant;
    printf("Montant a deposer : ");
    scanf("%f", &montant);
    
    if (montant > 0) {
        c.solde += montant;
        printf("Depot reussi \n Nouveau solde: %.2f MAD\n", c.solde);
    } else {
        printf("Montant invalide.\n");
    }
}
void Verifie_auto() {
    if (!clientCree) {
        printf("Veuillez creer un profil d'abord\n");
        return;
    }

    if (c.solde <= 0) {
        printf("Solde insuffisant Veuillez deposer de l'argent\n");
    } else {
        printf("Solde suffisant pour achat \n");
    }
}





















int main(){

int choix;  

do {
printf("  === SYSTEME D'ACHAT CLIENT ===\n");

printf( " _________Gestion du profil client_______\n");
printf("-----> 1.Creation de profil     :\n");
printf("-----> 2.Modification du profil :\n");
printf("-----> 3.Consultation du profil :\n");
printf("-----> 4.Generation email       :\n");

printf("__________ Gestion du solde virtuel________\n");
printf("-----> 5.Consultation du solde    :\n");
printf("-----> 6.Depot d'argent           :\n");
printf("-----> 7.Vérification automatique :\n");

printf(" _________Consultation des produits_________\n");
printf("-----> 8.Affichage catalogue :\n" );
printf("-----> 9.Recherche produits  :\n" );
printf("-----> 10.Tri des produits   :\n" );
printf("-----> 11.Details produit    :\n" );  
printf("-----> 12.Produits predefinis:\n" );       

printf("__________Effectuer un achat__________\n");
printf("-----> 13.Effectuer un achat   :\n" ); 

printf("__________Mes statistiques__________\n");
printf("-----> 14.produit disponible     :\n" );
printf("-----> 15.produit non disponible :\n" );
printf("-----> 16.solde totale           :\n" );
printf("-----> 0 .Quitter l'application   : \n" );
printf(" Votre choix: ");
scanf("%d", &choix);


switch (choix ){
    case 1 :
    cree();
    break;
    case 2 :
    modifie();
    break;
    case 3 :
    consulte_profile();
    break;
    case 4 :
    generie();
    break;
    case 5:
    consulte_solde();
    break;
    case 6:
    Depot_argent();
    break;
    case 7:
    Verifie_auto();
    break;
    case 8:
    afficher_catallogue();
    break;
    case 9:
    recherche_produit();
    break;
    case 10:
    tri_produits();
    break;
    case 11:
    details_produit();
    break;
    case 12:
    Produits_predefinis();
    break;
    case 13:
    Effectuer_achat();
    break;
    case 14:
    produit_disponible();
    break;
    case 15:
    produit_non_disponible();
    break;
    case 16:
    solde_totale();
    break;
    case 0 :
   printf("Youssef vous salue. Au revoir\n");
    break;
default:printf("Choix invalide\n");
    break;
}


} while (choix !=0);
return 0; 




}
