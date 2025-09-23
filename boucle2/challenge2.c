#include <stdio.h>
#include <stdlib.h>

int main(){
    int l, i, j ;
    printf("saisir un entier :"); 
    scanf("%d",&l);

    for (i = 1 ; i<l+1;i++){
        for(j=1;j<l-i;j++){
            printf(" ");
        }

        for (j = 1; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }


    return 0;
}