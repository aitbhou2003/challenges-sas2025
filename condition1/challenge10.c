#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int anne , moi , jour ;
    printf("saisir l'anne :");
    scanf("%d",&anne);
    printf("saisir le moi :");
    scanf("%d",&moi);
    printf("saisir le jour :");
    scanf("%d",&jour);

    printf("%d/%d/%d\n",jour,moi,anne);
    switch (moi)
    {
    case 1:
        printf("%d-janvier-%d",jour,anne);
        break;
        
    case 2:
        printf("%d-février-%d",jour,anne);
        break;
    
    case 3:
        printf("%d-mars-%d",jour,anne);
        break;
    case 4:
        printf("%d-avril-%d",jour,anne);
        break;
    case 5:
        printf("%d-mai-%d",jour,anne);
        break;
    case 6:
        printf("%d-juin-%d",jour,anne);
        break;
    case 7:
        printf("%d-juillet-%d",jour,anne);
        break;
    case 8:
        printf("%d-août-%d",jour,anne);
        break;
    case 9:
        printf("%d-septembre-%d",jour,anne);
        break;
    case 10:
        printf("%d-octobre-%d",jour,anne);
        break;
        
    case 11:
        printf("%d-novembre-%d",jour,anne);
        break;
    case 12:
        printf("%d-décembre-%d",jour,anne);
        break;

    
    default:printf("error!!!!!!!!!!!!!!!!!!!!");
        break;
    }
    return 0 ;
}
