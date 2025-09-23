#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = -2 ;
    while (a<=0)
    {
        printf("saisir une entier positive :");
        scanf("%d",&a);
    }
    

    

    if ( a%2 == 0 )
        printf("le nombre %d est paire ",a);
    else
    printf("le nombre %d est impaire",a);
}
    