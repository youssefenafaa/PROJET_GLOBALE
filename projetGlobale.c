#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_NOM 50
#define TAILLE_PRENOM 50
#define TAILLE_EMAIL 50
#define NB_PRODUITS 10


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
    {1, "Ordinateur" , "Electronique", 799.0, 5, "Ordinateur performant"},
    {2, "Smartphone", "Electronique", 499.0, 10, "Ecran AMOLED"},
    {3, "Casque ", "Accessoires", 89.0, 15, "Casque Bluetooth"},
    {4, "Souris", "Accessoires", 25.0, 20, "Souris sans fil"},
    {5, "Clavier", "Accessoires", 45.0, 12, "Clavier mécanique"},
    {6, "Tablette", "Electronique", 299.0, 8, "Tablette 10 pouces"},
    {7, "Imprimante", "Electronique", 150.0, 4, "Imprimante jet d'encre"},
    {8, "Disque ", "Accessoires", 99.0, 10, "1 To USB 3.0"},
    {9, "Webcam", "Accessoires", 59.0, 7, "Webcam HD 1080p"},
    {10, "Chargeur ", "Accessoires", 19.0, 25, "Charge rapide 20W"},
};




int idAuto = 1;
Client c;          
int clientCree = 0;    

void  cree_profil() {
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

void modifie_profil() {
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

void generie_email() {
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
        printf("Montant invalide\n");
    }
}

void Verifie_auto() {
    if (!clientCree) {
        printf("Veuillez creer un profil d'abord\n");
        return;
    }

    if (c.solde <= 0) {
        printf("Solde insuffisant Veuillez deposer de l'argent\n");
    }
        else {
         printf("Solde suffisant pour achat \n");
        }
}

void afficher_catallogue(){
    printf("______ Votre catallogue ______\n");
    for (int i = 0; i < NB_PRODUITS ; i++)
    {
        printf("%d | %s | %s | %.2f | stock:%d\n %s",
               catalogue[i].idProduit,catalogue[i].nom,catalogue[i].categorie,
               catalogue[i].prix,catalogue[i].stock,catalogue[i].description);
    }
    

}

void recherche_produit(){
 
 char n_recherche[50];
 int fn = 0;
 

     printf("Donne le nom de ce produit:\n ");
     scanf("%s",n_recherche);
         for ( int i = 0; i <NB_PRODUITS ; i++)
            {
                 if (strcmp(catalogue[i].nom,n_recherche)==0){
                    
                 printf("%d | %s | %s | %.2f | stock:%d \n %s\n",
                 catalogue[i].idProduit,catalogue[i].nom,catalogue[i].categorie,
                 catalogue[i].prix,catalogue[i].stock,catalogue[i].description);
                 fn =1;
                }  
                 
            }
            
                if(!fn) 
                    printf("ce n'est pas disponible\n");
                 
}

void tri_produits(){
    int ch;
    printf ("\n trier par :\n 1.prix(croissant) \n 2.prix(decroissant)\n 3.nom(a-z)\n");
    printf("votre choix:");
    scanf("%d",&ch);

    for (int i = 0; i < NB_PRODUITS-1; i++)
    {
        for (int j = i+1; j < NB_PRODUITS ; j++)
        {
            int condition = 0;
        if (ch == 1 && catalogue[i].prix > catalogue[j].prix)
            condition = 1;

        else if (ch == 2 && catalogue[i].prix < catalogue[j].prix)
            condition = 1;

        else if (ch == 3 && strcmp(catalogue[i].nom, catalogue[j].nom)>0)
            condition = 1;
                 
             if (condition)

             { Produit tmp = catalogue[i];
              catalogue[i]= catalogue[j];
              catalogue[j] = tmp;
             }
             
         }
        
    }
    
    printf(" Voici le nouveau catalogue:\n");
    for (int  i = 0; i < NB_PRODUITS ; i++)
    {
        printf ("%s - %.2f \n", catalogue[i].nom,catalogue[i].prix);
    }
    
}
   
void details_produit() {
    int id;
    printf("Entrez l'id du produit : ");
    scanf("%d", &id);

    for (int i = 0; i < NB_PRODUITS; i++) {
        if (catalogue[i].idProduit == id) {
            printf("Details du produit :\n");
            printf("Nom : %s\n", catalogue[i].nom);
            printf("Categorie : %s\n", catalogue[i].categorie);
            printf("Prix : %.2f MAD\n", catalogue[i].prix);
            printf("Stock : %d\n", catalogue[i].stock);
            printf("Description : %s\n", catalogue[i].description);
            return;
        }
    }
    printf("Produit introuvable avec cet id\n");
}

void Produits_predefinis() {
    char categorie[30];
    int trouve = 0;

    printf("Entrez la categorie : ");
    scanf("%s", categorie);

    printf("Produits dans la categorie %s:\n", categorie);
    for (int i = 0; i < NB_PRODUITS; i++) {
        if (strcmp(catalogue[i].categorie, categorie) == 0) {
            printf("%d | %s | %.2f MAD | Stock: %d\n", 
                    catalogue[i].idProduit, 
                    catalogue[i].nom, 
                    catalogue[i].prix, 
                    catalogue[i].stock);
            trouve = 1;
        }
    }
    
    if (!trouve) {
        printf("Aucun produit trouve dans cette catégorie.\n");
    }
}

void Effectuer_achat() {
    if (!clientCree) {
        printf("Veuillez d'abord creer un profil \n");
        return;
    }

    int id, quantite;
    printf("Entrez l'id du produit a acheter : ");
    scanf("%d", &id);
    printf("Quantite a acheter : ");
    scanf("%d", &quantite);

    for (int i = 0; i < NB_PRODUITS; i++) {
        if (catalogue[i].idProduit == id) {
            float total = catalogue[i].prix * quantite;

            if (quantite > catalogue[i].stock) {
                printf("Stock insuffisant \n Stock disponible : %d\n", catalogue[i].stock);
                return;
            }

            if (total > c.solde) {
                printf("Solde insuffisant \n  Solde actuel : %.2f MAD\n", c.solde);
                return;
            }

            
            catalogue[i].stock -= quantite;
            c.solde -= total;
            printf("Achat effectue avec succes \n");
            printf("Nouveau solde : %.2f MAD\n", c.solde);
            return;
        }
    }

    printf("Produit introuvable avec cet id \n");
}


void produit_disponible() {
    printf("Produits disponibles en stock :\n");
    for (int i = 0; i < NB_PRODUITS; i++) {
        if (catalogue[i].stock > 0) {
            printf("%d | %s | %.2f MAD | Stock: %d\n",
                   catalogue[i].idProduit, catalogue[i].nom,
                   catalogue[i].prix, catalogue[i].stock);
        }
    }
}

void produit_non_disponible() {
    printf("Produits en rupture de stock :\n");
    int trouve = 0;
    for (int i = 0; i < NB_PRODUITS; i++) {
        if (catalogue[i].stock == 0) {
            printf("%d | %s | %.2f MAD\n",
                   catalogue[i].idProduit, catalogue[i].nom, catalogue[i].prix);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Tous les produits sont actuellement en stock \n");
    }
}


void solde_totale() {
    float total = 0;
    for (int i = 0; i < NB_PRODUITS; i++) {
        total += catalogue[i].prix * catalogue[i].stock;
    }
    printf("Valeur totale des produits en stock : %.2f MAD\n", total);
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
printf("-----> 7.Verification automatique :\n");

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
printf("-----> 0 .Quitter l'application  : \n" );
printf(" Votre choix: ");
scanf("%d", &choix);


switch (choix ){
    case 1 :
    cree_profil();
    break;
    case 2 :
    modifie_profil();
    break;
    case 3 :
    consulte_profile();
    break;
    case 4 :
    generie_email();
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
   printf("M.Youssef vous salue. Au revoir\n");
    break;
default:printf("Choix invalide\n");
    break;
}


} while (choix !=0);
return 0; 




}







   













