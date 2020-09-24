#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define true 1

struct my_time{
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
};

void true_time(struct my_time *ptr_tm){
    ptr_tm->hour=(ptr_tm->sec / 3600) % 24 + 4;
    ptr_tm->min = (ptr_tm->sec % 3600) / 60;
    ptr_tm->sec %= 60;
}

int main(void){
    struct my_time cur_tm;
    struct my_time *ptr_tm;

    ptr_tm = &cur_tm;
    cur_tm.sec = time(0);
    true_time(ptr_tm);

    printf("Time = %d:%d:%d\n",cur_tm.hour,cur_tm.min,cur_tm.sec);
    system("pause");
    return 0;
}