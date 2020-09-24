#include <stdio.h>

#define R 4
#define C 5

int main()
{
    printf("Enter your array to change rows with max and min elements:\n\n");
    int array_2x [R][C];// где R-строки, С-стоблбцы
    int max_elem, min_elem, temporary;// последний - буферная переменная для замены строк
    int i,j, min_row, max_row ;//счетчики для циклов и переменные для запоминания строки 
    i =0; j = 0;min_row = 0; max_row = 0;

    for(i=0; i < R; ++i)//заполнение 
        for (j=0; j < C; ++j)
           scanf("%d", &array_2x[i][j]);
    max_elem = array_2x[0][0], min_elem=array_2x[0][0];//минимальный и максимальный элементы 

    for(i=0; i < R; ++i)//поиск макс и мин элемента + запоминание строк
        for (j=0; j < C; ++j){
            if(max_elem < array_2x[i][j]){
                max_elem = array_2x[i][j];
                max_row = i;
            }
            if (min_elem > array_2x[i][j]){
                min_elem = array_2x[i][j];
                min_row = i;
            }
        }

    for(j=0; j < C; ++j){// сама замена
        temporary = array_2x[max_row][j];
        array_2x[max_row][j] = array_2x[min_row][j];
        array_2x[min_row][j] = temporary;
    }

    for(i=0; i < R; ++i){// вывод
        for (j=0; j < C; ++j)
            printf("\t%d", array_2x[i][j]);
            printf("\n");
        }
    _flushall();
    getchar();
    return 0;
}