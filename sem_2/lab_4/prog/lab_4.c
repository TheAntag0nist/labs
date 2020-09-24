#include <stdio.h>
#include <stdlib.h> //для работы system("pause");

//размер массива string
#define SIZE 1024
//константы для флага (flag)
#define FALSE 0
#define TRUE 1

void get_mass(char mass[]){
    char ch;
    int i=0;

    while((ch=getchar())!=EOF && i!=SIZE-1)
        mass[i++]=ch;
    mass[i]='\0';
}

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
    char string[SIZE];
    char temp=' ';
    int flag=FALSE,   //флаг для проверки слова
        begin_word=0,  //счетчик слов
        rep_char=0,   //счетчик повторов подряд идущих символов
        i=0;          //счетчик для циклов
    
    get_mass(string);

    while(string[i]!='\0'){
        if(string[i]==' ' || string[i]=='.' || string[i]==',' || string[i]=='\t' || string[i]=='\n' || string[i]=='!' || string[i]=='?'){
            temp=string[i];
            //вырезаем слово, в котором нет подряд идущих одинаковых символов
            if(rep_char==0 && flag==TRUE)
                for(begin_word;begin_word<i;begin_word++)
                    string[begin_word]=' ';
            rep_char=0;
            flag=FALSE;
        }else{
            if(flag==FALSE){
                //запоминаем начало слова
                begin_word=i;
                flag=TRUE;
            }
            //проверяем на подряд идущие одинаковые символы
            if(string[i]==temp || (string[i]>=48 &&string[i]<=57))
                rep_char++;
            //сохраняем текущий символ для последующей проверки
            temp=string[i];
        }   
        i++;
    }

    display_mass(string);

    system("pause");
    return 0;
}