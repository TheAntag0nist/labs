#include <stdio.h>
#include <stdlib.h> //для работы system("pause");

//размер массива string
#define SIZE 1024
//константы для флага (flag)
#define FALSE 0
#define TRUE 1
#define CORRECT_WORD 2
void display_mass(char mass[]){
    int i=0;

    while(mass[i]!='\0'){
        //выводим без лишних пробелов
        if(mass[i]==' ' && mass[i+1]!=' ')
            putchar(mass[i]);
        else if(mass[i]!=' ')
            putchar(mass[i]);
        i++;
    }
}

int main(void){
    char string[SIZE],
         vow_let[]="AEIUOaeiuo";
    char temp_1=' ',temp_2=' ';

    int flag=FALSE,   //флаг для проверки слова
        begin_word=0,  //счетчик слов
        rep_char=0,   //счетчик повторов подряд идущих символов
        i=0,j=0;          //счетчик для циклов
    
    while((temp_1=getchar())!=EOF && i!=SIZE-1)
        string[i++]=temp_1;
    string[i]='\0';

    i=0;
    temp_1=' ';

    while(string[i]!='\0'){
        if(string[i]==' ' || string[i]=='.' || string[i]==',' || string[i]=='\t' || string[i]=='\n' || string[i]=='!' || string[i]=='?'){
            temp_1=' ';
            temp_2=' ';

            if(flag==CORRECT_WORD)
                for(begin_word;begin_word<i;begin_word++)
                    string[begin_word]='*';

            rep_char=0;
            flag=FALSE;
        }else{
            if(flag==FALSE){
                //запоминаем начало слова
                begin_word=i;
                flag=TRUE;
            }
            //проверяем два символа
            temp_1=string[i];
            temp_2=string[i+1];
 
            for(j=0;j<11;j++)
                if(temp_1==temp_2 && vow_let[j]==temp_1){
                    flag=CORRECT_WORD;
                    break;
                }
                else if(vow_let[j]==temp_1 || vow_let[j]==temp_2)
                    rep_char++;             
            if(rep_char==2)
                flag=CORRECT_WORD;
            else
                rep_char=0; 
                
        }   
        i++;
    }

    display_mass(string);

    system("pause");
    return 0;
}