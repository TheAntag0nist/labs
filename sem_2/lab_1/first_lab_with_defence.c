#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//Compiler version gcc  6.3.0

#define PI 3.14
#define MAX 128

float cin_float(){
  char buff[MAX],ch;
  int i=0,nums_of_dots=0;
  float num;

  while((ch=getchar())!='\n' && i<MAX){
      if((ch>47 && ch<58) || (ch==46 && nums_of_dots==0)){
        if(ch=='.')
            nums_of_dots=1;
          buff[i]=ch;
          i++;
      }
  }
  num=atof(buff);
  return num;
}

int main(){
  float H,R,D,volume,R_2;
  char true_or_f='y';

  while(true_or_f!='n'){
  //ввод данных с защитой от дурака
      printf("Enter height of conus.\n");
      printf("H=");
      H=cin_float();

      printf("Enter radius.\n");
      printf("R=");
      R=cin_float();

      printf("Enter height of cut: ");
      printf("D=");
      D=cin_float();
      
      //нахождение радиуса сечения
      R_2=D/H*R;
      if(R>0.0 && D<R && D>0.0)
            true_or_f='n';
      else  {
          printf("Error. Repeat(y/n):");
          true_or_f=getchar();
      }
  }

  /*Считаем по формуле 
  и выводим результат*/
  if(R>0.0 && D<R && D>0.0){
    volume=1.0/3.0*PI*(H-D)*(R*R+R*R_2+R_2*R_2);
    printf("Volume: %.2f", volume);
  }else
    printf("Close.");

  //чтобы консоль не закрылась
  getchar();
  return 0;
}
