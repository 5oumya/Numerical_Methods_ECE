#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// define the function
#define f(x)  (1/(1+pow(x,2)))

int main ()
{
    int n ;//subinterval
    float u,l,h; //upper and lower limit and step size
    float k, integration; // k for Xn values and integration for result

    printf("u,l,n");
    scanf("%f%f%d",&u,&l,&n);

    h=(u-l)/n;

    integration=f(l)+f(u);
    for(int i=1;i<n;i++)
    {
        k=l+i*h;
        if (i%2==0)
            integration=integration+2*f(k);
        else
            integration=integration+4*f(k);
    }
    integration=integration*h/3;
    printf("%f",integration);
    return 0;
}