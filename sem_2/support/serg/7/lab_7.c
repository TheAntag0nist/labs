#include <stdio.h>
#include <stdlib.h>

int main(void){
    long long test_num, temp,temp_2,
                main_mask = 0xffffffff00000000,
                mask_left = 0x8000000000000000,
                mask_right = 0x0000000000000001,
                support_mask = 0x7fffffffffffffff;
    int i;
    char true_or_f;

    printf("test_num = ");
    scanf("%lld",&test_num);

    temp = test_num & main_mask;
    test_num &= ~main_mask;

    for(i=0;i<31;++i){
        temp_2 = temp & mask_left;
        temp_2 >>=63-2*i;
        if (temp_2 == (test_num & mask_right)){
            true_or_f = 't';
            mask_right <<=1;
            mask_right &= ~main_mask;
            mask_left >>= 1;
            mask_left &= support_mask;
        }
        else{
            true_or_f = 'f';
            break;
        }
    }

    printf("true_or_f = %c\n",true_or_f);
    system("pause");
    return 0;
}