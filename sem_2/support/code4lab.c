#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

 #define MAXLEN 1000

int main(void)
{
int lowest_point,
    highest_point,
    i, j, k,
    FirstVowel,
    SecondVowel;

char current_line[MAXLEN],
    line_for_output[MAXLEN],
    vowel_letters[] = "AEIUOaeiuo",
    buffer[MAXLEN];


printf("Enter your line:");

while ((current_line[MAXLEN] = getchar()) != '\n')
{

    for (i = 0; i < MAXLEN; i++) 
    {
        lowest_point = i; j = 0;

        while (current_line[i] != '.' && current_line[i] != ','&& current_line[i] != ' ' && current_line[i] != '\n') 
        {
        buffer[j] = current_line[i]; 
        i++; j++;
        }
        highest_point = i;

        for (j = 0; j < highest_point - lowest_point; j++) 
        {

            FirstVowel = 0; SecondVowel = 0;

            for (k = 0; k < 10; k++) 
            {
                if (buffer[j] == vowel_letters[k])
                FirstVowel = 1;
                if (buffer[j + 1] == vowel_letters[k])
                SecondVowel = 1;
            }
            if (FirstVowel * SecondVowel) 
            {
                for (j = lowest_point; j < highest_point; j++)
                    current_line[j] = 42;
                if  (lowest_point - 1 >= 0)
                current_line[lowest_point - 1] = 42;
                break;
            }
        }
    }
}
 

for (i = 0;i<sizeof(current_line); i++) 
    if (current_line[i] != 42) 
        line_for_output[i++] = current_line[i];


    printf("\n%s\n", line_for_output);
    system("pause");
return 0;
}