#include <stdio.h>
#include <stdlib.h>

int main(){
    int a , n , i , j;
    printf("saisir la taiile de tabeaux : ");
    scanf("%d",&n);
    int T[n] ;
    printf("remplir le tableaux : \n");
    for ( i = 0; i < n; i++)
    {
        printf("T[%d] : ",i+1);
        scanf("%d",&T[i]);
        printf("\n");
    }

    
    printf("saisir l'élément à rechercher : ");
    scanf("%d",&a);
    for (i=0;i<n;i++){
        if (T[i]==a)
        {
            printf("l'element rechetche existe en T[%d] = %d\n",i+1,a)  ;
        }
         
    }



    return 0 ;
}