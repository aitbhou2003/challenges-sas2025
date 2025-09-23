#include <stdio.h>
#include <stdlib.h>

int main(){
    int a ;
    printf("saisir une entier :");
    scanf("%d",&a);
    int x =0 ;
    do
    {
        a = a/10;
        x++;
    } while (a!=0);
    printf("Nombre de chiffres = %d",x);
    

    return 0;
}