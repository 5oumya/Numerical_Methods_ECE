#include <stdio.h>
#include <math.h>

float f (float x){
    return (pow(x,2)-(8*x)+11);
}
float df (float x){
    return ((2*x)-8);
}

int main()
{
    int n,i;
    float x,y,x0;

    printf("Enter the number of iterations: ");
    scanf("%d",&n);
    printf("Enter the initial value of x: ");
    scanf("%f",&x0);

    x=x0;
    for(i=0;i<n;i++)
    {
        x=x-(f(x)/df(x));
    }
    printf("The root of the equation is: %f",x);
}