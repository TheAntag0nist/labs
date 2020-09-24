#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void display_bits_ll(long long num){
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
    long long test_1,temp_1,temp_2,
        mask_1=0xff00000000000000,
        mask_2=0x00000000000000ff,
        //support_mask необходимо для сдвига вправо
        support_mask=0x00ffffffffffffff;
    int i;

    //меняем размер консоли
    system("mode con cols=110 lines=25");

    //ввод данных
    printf("Enter test number.\ntest_1 (long long) = ");
    scanf("%lld",&test_1);

    //вывод в двоичном виде
    printf("Binary test_1 = ");
    display_bits_ll(test_1);

    //обработка числа
    for(i=0;i<4;++i){
        temp_1 = test_1 & mask_1;
        temp_2 = test_1 & mask_2;
        temp_1 >>= (7-2*i)*8;
        temp_2 <<= (7-2*i)*8;
        test_1 &= ~(mask_1 | mask_2);
        mask_1 >>= 8;
        mask_1 &= support_mask;
        mask_2 <<= 8;
        test_1 += temp_1 + temp_2;
        display_bits_ll(test_1);
    }

    //выводим в двоичном виде
    printf("After processing...\nBinary test_1 = ");
    display_bits_ll(test_1);

    system("pause");
    return 0;
}