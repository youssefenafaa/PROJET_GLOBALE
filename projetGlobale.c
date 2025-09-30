#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_NOM 1
#define TAILLE_PRENOM 1
#define TAILLE_EMAIL 1

typedef struct {
    int idClient;                  
    char nom[TAILLE_NOM];         
    char prenom[TAILLE_PRENOM];   
    char email[TAILLE_EMAIL];     
    float solde;                  
} Client;








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


switch ( option){
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
    Vérifie_auto();
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


} while (option !=0);
return 0; 




}










   













