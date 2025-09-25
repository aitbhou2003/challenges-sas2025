#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[20];
    int num ;

}Carnet;

void ajouter_contact(Carnet *c){
    printf("saisir le le nom : ");
    scanf(" %[^\n]s",c->nom);
    printf("saisir le numero : ");
    scanf("%d",&c->num);

}

void afficher(int size, Carnet *c){
    for (int i = 0; i < size; i++)
    {   printf("***************************************************\n");
        printf("nom %d : %s  num %d : %d\n",i+1,c[i].nom,i+1,c[i].num);
        printf("***************************************************\n");
    }
}
void rechercher(Carnet *c, int size){
    char nom_rechercer[20] ;
    int i=0 ;
    printf("saisir le nome que tu peux recherche : ");
    scanf(" %[^\n]s",nom_rechercer);
    for(;i<size;i++){
        if (strcmp(c[i].nom ,nom_rechercer)==0){
            printf("***************************************************\n");
            printf("nom %d : %s  num %d : %d\n",i+1,c[i].nom,i+1,c[i].num);
            printf("***************************************************\n");


        }

    }
    if (strcmp(c[i].nom ,nom_rechercer)!=0)
            printf("le nome n'exist pas \n");


}
int position(Carnet *c , int size,char *N){

    for (int i =0 ; i<size ; i++){
        if (strcmp(c[i].nom ,N)==0){
            return i ;
        }

    }
    return -1 ;
}


void supprimer(Carnet *c,int *size){
    char nom_delet[20] ;
    int i ;
    printf("saisir le nome que tu peux suprime : ");
    scanf(" %[^\n]s",nom_delet);
    int x = position(c,*size,nom_delet);
    if (x>-1){
        for (i=0;i<*size;i++){
            c[i] = c[i+1];
        }
        printf("le contact est suprime .");
    }
    if (x ==-1){
        printf("le nome n'exist pas");
    }




}

int main(){
    int menu ;
    int  n  ,i, j, id_c = 0;

    Carnet c[50] ;







    do{
        printf("menu :\n1- Ajouter un contact (nom + téléphone)\n2- Afficher tous les contacts\n3- Rechercher un contact par son nom\n4- Supprimer un contact par son nom\n5- Quitter\n" );
        printf("saisir votre choix :");
        scanf("%d",&menu);

    switch (menu){
        case 1: ajouter_contact(&c[id_c++]);
            break;

        case 2:afficher(id_c,c);
            break;

        case 3:rechercher(c,id_c);
            break;

        case 4:supprimer(c,&id_c);
            break;

        case 5: printf("quitte");
                return 0 ;
            break;
        default: printf("error !!!!!!!!");
            break;
        }

    }while(menu!=5);


    return 0 ;
}
