#include <stdio.h>
#include <stdlib.h> //для работы system("pause");

#define SIZE 512
#define FALSE 0
#define TRUE 1

//ввод массива с добавлением символа конца строки
void get_mass(char mass[]){
    char ch;
    int i=0;

    while((ch=getchar())!=EOF && i!=SIZE-1)
        mass[i++]=ch;
    mass[i]='\0';
}

//функция вывода без лишних пробелов
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

int main(){
    char string[SIZE];
    int i=0,
        cnt_words=0,
        begin_word,
        flag=FALSE;

    get_mass(string);

    //гоняемся по массиву
    while(string[i]!='\0'){
        //проверяем разделитель сейчас или нет
        if(string[i]==' ' || string[i]=='.' || string[i]==',' || string[i]=='\t' || string[i]=='\n' || string[i]=='!' || string[i]=='?'){
            //вырезаем слово, если оно четное и  проверяем флаг (чтобы проверить было ли слово до этого)
            if(cnt_words%2==0 && flag==TRUE)
            //от начала до текущего символа разделителя замещаем символы пробелами
                for(begin_word;begin_word<i;begin_word++)
                    string[begin_word]=' ';
            //меняем состояние флага (потому что встретился разделитель)
            flag=FALSE;
        }else {
            /*
              если сейчас не разделитель 
              и до этого флаг был FALSE
              то сейчас начало слова
              (TRUE- сейчас считывается слово, FALSE - значит сейчас разделители)
            */
            if(flag==FALSE){
                //запоминаем начало слова
                begin_word=i;
                //считаем какое слово по счету
                cnt_words++;
                flag=TRUE;
            }
        }   
        i++;
    }

    display_mass(string);
    system("pause");
    return 0;
}