#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void display_bits(long long num){
    int i;
    for(i=0;i<64;++i){
        //0x8000000000000000 в двоичной версии 100...000 (63 нуля)
        printf("%d",(num & 0x8000000000000000) ? 1: 0);
        num<<=1;
        if((i+1) % 8 == 0)
            printf("  ");
    }
    printf("\n");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(void){
    //объявляем переменные
    long long test_1;
    int i;
    char* ptr;

    //меняем размер консоли
    system("mode con cols=110 lines=25");

    //ввод данных
    printf("Enter test number.\ntest_1 (long long) = ");
    scanf("%lld",&test_1);

    //выводим в двоичном виде
    printf("binary version test_1 = ");
    display_bits(test_1);

    // начальное время
    clock_t start_time =  clock(); 

    //обработка числа
    ptr =(char*) (&test_1); 
    for(i=0;i<sizeof(long long)/2;++i){
        *(ptr+i) =*(ptr+i)+ *(ptr+sizeof(long long)-i-1);
        *(ptr+sizeof(long long)-i-1) = *(ptr+i)- *(ptr+sizeof(long long)-i-1);
        *(ptr+i)-=*(ptr+sizeof(long long)-i-1);
    }

    //вывод результата
    printf("Result = %lld\n",test_1);
    printf("Result = ");
    display_bits(test_1);

    //время работы программы 
    // конечное время
    clock_t end_time = clock(); 
    // искомое время
    double search_time = (double) (end_time - start_time) / CLOCKS_PER_SEC; 
    printf("Time = %f\n",search_time);

    system("pause");
    return 0;
}