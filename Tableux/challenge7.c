#include <stdio.h>
#include <stdlib.h>


void tableux_croissant(int *tab, int n){
    int  i, j ;
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (tab[i]<tab[j]){
                tab[i] = tab[i] + tab[j];
                tab[j] = tab[i] - tab[j];
                tab[i] = tab[i] - tab[j];
        }
        
        }
    }
     printf("le tableux croissant ets :\n");

    for(i=0;i<n;i++){
        printf("tab[%d] = %d\n",i+1,tab[i]);
    }

}



int main(){
    int n , tab[50],i;
    printf("saisir la taille de tableux : \n");
    scanf("%d",&n);
    printf("donc remplir le tableux : \n");
    for (i=0;i<n;i++){
        printf("tab[%d] = ",i+1);
        scanf("%d",&tab[i]);
    }
    printf("****************\n");
    tableux_croissant(tab,n);



    return 0 ;
}