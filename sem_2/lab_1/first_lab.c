#include <stdio.h>
#include <conio.h>//для _getch();

//Compiler version gcc  6.3.0

#define PI 3.14

int main(){
  float H,R,D,volume,R_2;
  
  //ввод данных
  printf("Enter height of conus: ");
  scanf("%f",&H);
  printf("Enter radius: ");
  scanf("%f",&R);
  printf("Enter height of cut: ");
  scanf("%f",&D);
  
  //нахождение радиуса сечения
  R_2=D/H*R;
  
  /*проверяем корректность введенных данных.
  Если все верно, то считаем по формуле 
  и выводим результат*/
  if(H>D && H>0.0 && R>0.0){ 
    volume=1.0/3.0*PI*(H-D)*(R*R+R*R_2+R_2*R_2);
    printf("Volume: %.2f", volume);
  }else 
    printf("Error.");

  //чтобы консоль не закрылась
  _getch();
  return 0;
}
