#include <stdio.h>
#include <stdlib.h>

int main(){

    int anne,i ,moi , jour , heur ,minut ,second;
    printf("entre une anne :");
    scanf("%d",&anne);

    if (anne%4 == 0 && anne%100!=0 ){
        moi = 12 ;
        jour = 366 ;
        heur = 366*24;
        minut = heur*60;
        second = minut*60;
    }else{
        moi = 12 ;
        jour = 365 ;
        heur = 365*24;
        minut = heur*60;
        second = minut*60;

    }
    printf("-%d\n",anne%4);
    printf("-moi : %d \n-jour : %d \n-heur : %d \n-minut : %d \n-second : %d \n",moi,jour,heur,minut,second );




    return 0;
}
