#include <stdio.h>
#include <stdlib.h>

int main(void){
    long long test_num,
                mask=0x8000000000000000,
                support_mask=0x7fffffffffffffff,
                temp;
    int i;
    scanf("%lld",&test_num);

    for(i=63;i>=0;i--){
        temp=test_num & mask;
        if(temp!=0){
            test_num &= mask;
            break;
        }
        mask>>=1;
        mask&=support_mask;
    }


    printf("test_num = %lld", test_num);
    printf("i = %d\n",i);
    system("pause");
    return 0;
}