#include <stdio.h>
#include <stdlib.h>

int main(){
    int a , i, p ;
    printf("saisir un entier :");
    scanf("%d",&a);
    for (i=10;i>=1;i--){
        p = a * i ;
        printf("%d * %d = %d \n",a,i,p);
    }

    return 0;
}