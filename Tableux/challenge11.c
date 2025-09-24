#include <stdio.h>
#include <stdlib.h>

int main(){
    int a , n , i , b;
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

    
    printf(" la valeur à remplacer : ");
    scanf("%d",&a);

    printf(" la valeur à remplacer : ");
    scanf("%d",&b);

    for (i=0;i<n;i++){
        if (T[i] == a){
            T[i] = b ;
        }
    }
    printf("le tableux avec les element remplacer est : \n");
    for (i=0 ; i<n ; i++){
        printf("T[%d] = %d\n",i+1,T[i]);
    }


    



    return 0 ;
}