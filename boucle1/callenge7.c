#include <stdio.h>
#include <stdlib.h>

int main(){
    int a   ;
    int invers = 0 ;
    printf("saosir un entier :");
    scanf("%d",&a);
    printf("l'inverse de %d",a);
    do
    {
        invers = invers*10 + a%10 ;
        a = a / 10 ;
    } while (a!=0);

    printf(" est %d",invers);
    
    
    

    return 0 ;
}