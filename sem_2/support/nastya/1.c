#include<stdio.h>
#include<stdlib.h>

#define N 3
#define K 4

void display_mass(int mass[N][K]){
    int i,j;
    for (i = 0; i < N; i++){
        for (j = 0; j < K; j++)
            printf("mass[%d][%d] = %d\t", i, j, mass[i][j]);
        printf("\n");
    }
}

int main(void){
    // массив из N на K
    int x[N][K];
    // массив для сохранения значений среднего арифметического
    int avg[K];
    int i, j, k, sum, temp;

    for (i = 0; i < N; i++){
        for (j = 0; j < K; j++){
            printf("mass[%d][%d] = ",i,j);
            scanf("%d", &x[i][j]);
        }
    }

    printf("\n"); 

    for (i = 0; i < N; i++){
        sum = 0;
        for (j = 0; j < K; j++)
            sum += x[i][j];// среднее арифметическое в каждой строке
        avg[i] = sum / K;
    }
    
    //вывод массива
    display_mass(x);

    printf("\n\n");  

    for (i = 0; i < N; i++)
       printf("avg[%d] = %d\t", i,avg[i]);
    printf("\n");

    printf("\n"); 

    for(k = 0; k < N-1; ++k){
        if(avg[k]<avg[k+1]){
            for(i=0;i<K;++i){
                x[k][i]+=x[k+1][i];
                x[k+1][i]=x[k][i]-x[k+1][i];
                x[k][i]-=x[k+1][i];
            }
            avg[k]+=avg[k+1];
            avg[k+1]=avg[k]-avg[k+1];
            avg[k]-=avg[k+1];
        }
    }

    //вывод массива
    display_mass(x);

    printf("\n\n");  

    for (i = 0; i < N; i++)
       printf("avg[%d] = %d\t", i,avg[i]);
    printf("\n");

    system("pause");
    return 0;
}