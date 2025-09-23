#include <stdio.h>
#include <stdlib.h>

int main(){
    char L ;
    printf("saisir un lettre :");
    scanf(" %c", &L);

    switch(L)
    {
    case 'a': 
        printf("%c voyelle",L);
        break;
    case 'e': 
        printf("%c voyelle",L);
        break;
    case 'i': 
        printf("%c voyelle",L);
        break;
    case 'o': 
        printf("%c voyelle",L);
        break;
    case 'u': 
        printf("%c voyelle",L);
        break;
    
    default:
        printf("%c consonne",L);
        break;
    }

    



}