#include <stdio.h>
#include <stdlib.h>

int main(){
    int n , i ,j ;
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
    printf("\n");
    for(i=0,j=n-1;i<=j;i++,j--){
             T[i] = T[i] + T[j];
             T[j] = T[i] - T[j];
             T[i] = T[i] - T[j];
    }


    printf("le tableux inverse est : \n");
    for (i=0 ; i<n ; i++){
        printf("T[%d] = %d\n",i+1,T[i]);
    }

    


    return 0 ;
}
