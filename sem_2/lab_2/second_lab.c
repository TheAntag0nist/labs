#include <stdio.h>//printf и scanf
#include <conio.h>//для getchar
#include <math.h>//для функции pow()

int main(void){
    int num_elem,factor=1,i=0;
    float res=1.0,x,x_temp;

    printf("Nums of elements: ");
    scanf("%d",&num_elem);
    printf("Enter X: ");
    scanf("%f",&x);

    x_temp=x;
    
    if(num_elem>0 && x!=0){
        while(i!=(num_elem-1) && i<20){
            factor*=(i*2+2)*(i*2+1);
            res+=pow(-1,i+1)*pow(x,2)/factor;
            x*=x_temp; 
            i++;
        }
        printf("Result: %.6f",res);
    }else if(num_elem>0)
        printf("Result: %f",res);
    else
        printf("Error.");
    
	

    _flushall();//для очищения потока ввода
    getchar();
    return 0;
}