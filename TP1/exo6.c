#include <stdio.h>

double f(double x){
    return x*x-2;
}
double df(double x){
    double h=0.00001;
    return (f(x+h)-f(x))/h;
}
int main(void)
{
    int i;
    double x=1;
    for(i=1;i<5;i++)
    { 	x=x-f(x)/df(x);
    }
    printf("%f ", x);
    return 0;
}