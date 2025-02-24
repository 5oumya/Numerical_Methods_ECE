#include <stdio.h>
#include <math.h>
int main ()
{
    float a[20][20],h,f,d,r,y;
    int i,j,n,fact;
    printf("Enter the value of n:"); //Read the length of the table from user
    scanf("%d",&n);
    printf("Enter the values of x:"); // read the elements of the x coloumn.
    for(i=0;i<n;i++)
        scanf("%f",&a[i][0]);
    printf("Enter the values of y:"); // read the elements of the y coloumn.
    for(i=0;i<n;i++){
        scanf("%f",&a[i][1]);
    }
    //create the difference table
    for(j=2;j<n+1;j++)
    {
        for(i=0;i<n-j+1;i++)
        {
            a[i][j]=a[i+1][j-1]-a[i][j-1];
        }
    }
    printf("Enter the value of x for interpolation:"); //Take the input from user value of x 
    scanf("%f",&f);
    // initialize variable 
    h = a[1][0]-a[0][0];
    r=(f-a[0][0])/h;
    y=a[0][1];
    d=r,  fact=1;
    // Calculation
    for(j=2;j<=n;j++)
    {
        y += (d*a[0][j])/fact;
        d=d*(d-(j-1));
        fact *= j;
    }
    //output
    printf("For the value of x = %f \nThe value is %f.",f,y);
}