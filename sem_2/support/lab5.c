#include <stdio.h>

#define N 10
 
int main (void){
    int x[N], sum_mod = 0, sum_pos = 0 ,i;
 
    for ( i = 0; i < N; i++)
        scanf("%d", &x[i]);
 
    for ( i = 0; i < N; i++)
        if ( x[i] < 0 )
            sum_mod = sum_mod + x[i]*(-1); 
 
    for ( i = 0; i < N; i++)
        if ( x[i] > 0 )
            sum_pos = sum_pos + x[i];

    if ( sum_mod < sum_pos ){
        for ( i = 0; i < N; i++ ){
            if ( x[i] < 0 )
                x[i] = 0;
        }
    }    
    
    for ( i = 0; i < N; i++)
        printf("%d ", x[i]);
    printf("\n");
    
    printf("sum_mod = %d", sum_mod);
    printf("\n");
    printf("sum_pos = %d", sum_pos);
    printf("\n");

    getchar();
    getchar();
}