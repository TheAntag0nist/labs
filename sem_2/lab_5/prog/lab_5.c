#include <stdio.h>  //для scanf
#include <stdlib.h> //для system("pause")

#define SIZE 10

int main(void){
    int mass[SIZE];
    int i,max_sum,num_pair;

    for(i=0;i<=SIZE-1;++i){
        printf("num = %2d",i+1);
        printf(" mass[%d] = ",i);
        scanf("%d",&mass[i]);
    }

    max_sum=mass[0]+mass[1];
    num_pair=0;

    for(i=1;i<SIZE-1;++i){
        if(max_sum<(mass[i]+mass[i+1])){
            max_sum=mass[i]+mass[i+1];
            num_pair=i;
        }
    }

    printf("\nmax_sum = %d\nnum_pair = %d and %d\n",max_sum,num_pair+1,num_pair+2);

    system("pause");
    return 0;
}