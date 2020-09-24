#include <stdio.h>
#include <stdlib.h>

int main(void){
    int part_1=100,
        i;
    float part_2=13223.4f;
    double part_3=12.2;

    printf("Part_1 adress: 0x%x\n",&part_1);
    for(i=1;i<10;i++)
        printf("Part_1 adress: 0x%x\n",&part_1+i);
    printf("\n");

    printf("Part_2 adress: 0x%x\n",&part_2);
    for(i=1;i<10;i++)
        printf("Part_2 adress: 0x%x\n",&part_2+i);
    printf("\n");

    printf("Part_3 adress: 0x%x\n",&part_3);
    for(i=1;i<10;i++)
        printf("Part_3 adress: 0x%x\n",&part_3+i);
    printf("\n");

    printf("\n");
    system("pause");
    return 0;
}