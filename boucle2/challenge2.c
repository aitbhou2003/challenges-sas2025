#include <stdio.h>
#include <stdlib.h>

int main(){
    int l, i, j ;
    printf("saisir un entier :"); 
    scanf("%d",&l);

    for (i = 1 ; i<l+1;i++){
        for(j=1;j<l-1;j++){
            printf(" ");
        }

        for (j = 1; i < 2*1-1; j++)
        {
            printf("*");
        }
        
    }


    return 0;
}