#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main(){
    char ch;
    int flag=FALSE,
        cnt_words=0,
        cnt_chars=0;
    float avg;

    while((ch=getchar())!=EOF){
        if(ch==' ' || ch=='.' || ch==',' || ch=='\t' || ch=='\n' || ch=='!' || ch=='?'){
            if(flag=TRUE)
                cnt_words++;
            flag=FALSE;
        }
        else{
            flag=TRUE;
            cnt_chars++;
        }
    }

    avg=(float)(cnt_chars)/cnt_words;
    printf("Chars in word on average: %.2f",avg);
    getchar();
    return 0;
}