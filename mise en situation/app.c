#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char nom[100] ;
    int quantite , i;
    float prix ;
    printf("saisir le nome de produit : ");
    gets(nom);
    printf("saisir la quantite de produit : ");
    scanf("%d",&quantite);
    printf("saisir le prix de produit : ");
    scanf("%f",&prix);
    if (prix<=0){
        printf("erreur  le prix est négatif !!!");
     }
    else
        printf("Produit : %s, Quantité : %d, Prix : %f\n",nom,quantite,prix);
        if (quantite<10)
            printf("Stock faible, réapprovisionnez !\n");

quantite = 5;
for (i=0;i<quantite;i++){
    printf("%s\n",nom);
}





    return 0;
}