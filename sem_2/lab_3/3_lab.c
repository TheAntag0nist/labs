#include <stdio.h>

//константы для флага (flag)
#define FALSE 0
#define TRUE 1

int main(void){
    char ch=' ',temp='\0';
    int flag=FALSE,   //флаг для проверки слова
        cnt_words=0,  //счетчик слов
        rep_char=0;   //счетчик повторов подряд идущих символов
    //WIN+Z - EOF комбинация для Windows
    //WIN+D - EOF для Linux
    while((ch=getchar())!=EOF){
        if(ch==' ' || ch=='.' || ch==',' || ch=='\t' || ch=='\n' || ch=='!' || ch=='?'){
            flag=FALSE;
            temp='\0';
            if(rep_char>0){
                cnt_words++;
                rep_char=0;
            }
        }else{
            flag=TRUE;
            if(ch==temp && (ch<48 || ch >57))
                rep_char++;
            temp=ch;
        }   
    }
    printf("\nNumbers of words: %d\n",cnt_words);
    getchar();
    return 0;
}