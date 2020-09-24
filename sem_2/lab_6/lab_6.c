#include <stdio.h>
#include <stdlib.h> //для system() и malloc()
#include <time.h>   //для функции time(0) (time нужно для генерации случайных чисел)
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
void display_mass(int** mass,int n,int k){
    int i,j;
    
    for(i=0;i<n;++i){
        for(j=0;j<k;++j)
            printf("mass[%d,%d]=%2d ",i,j,mass[i][j]);
        printf("\n\n");
    }
    printf("\n");
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
void get_mass(int** mass,int n,int k){
    int i,j;

    if(n>=10 || k>=10){
        printf("Array is too big.\nWill be used random generation...\n");
        //инициализация генератора случайных чисел
        srand(time(0));
        //заполнение массива значениями от -5 до 5
        for(i=0;i<n;++i)
            for(j=0;j<k;++j){
                mass[i][j]=rand() % 10 - 5;
            }
    }
    else{
        for(i=0;i<n;++i)
            for(j=0;j<k;++j){
                printf("mass[%d,%d] = ",i,j);
                scanf("%d",&mass[i][j]);
            }
    }
    
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
int main(void){
    //объявление переменных
    int **mass;
    int k,n,i,j,cnt_even=0;

    //вводим данные о кол-ве рядов и столбцов
    printf("Enter nums of rows: ");
    scanf("%d",&n);
    printf("Enter nums of columns: ");
    scanf("%d",&k);

    //выделяем память под массив в heap
    //будем хранить строками
    mass=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;++i){
        mass[i]=(int*)malloc(k*sizeof(int));
    }

    printf("Heap was created...\nPress any key...");
    _flushall(); //очищаем поток ввода 
    getchar();
    printf("Start working...\n");

    //ввод массива
    get_mass(mass,n,k);

    //вывод массива
    display_mass(mass,n,k);

    printf("Processing...\n");
    //обработка массива
    for(i=0;i<k;++i){
        for(j=0;j<n;++j){
            if(mass[j][i] % 2 == 0)
                cnt_even+=1;
        }
        if(cnt_even>n/2)
            for(j=0;j<n;++j)
                mass[j][i]=0;
        cnt_even=0;
    }
    
    printf("Array after processing...\n");
    //вывод массива
    display_mass(mass,n,k);
    
    //очищаем память
    for(i=0;i<n;++i)
        free(mass[i]);  
    free(mass);

    system("pause");
    return 0;
}