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
        for(i=n-1;i>j-2;i--)
        {
            a[i][j]=a[i][j-1]-a[i-1][j-1];
        }
    }

    // Printing the difference table
    printf("\nDifference Table:\n");
    printf(" x\t   y\n");
    for (i = 0; i < n; i++) {
        printf("%0.2f", a[i][0]);
        for (j = 1; j < n ; j++) {
            printf("\t%0.2f", a[i][j]);
        }
        printf("\n");
    }


    printf("Enter the value of x for interpolation:"); //Take the input from user value of x 
    scanf("%f",&f);
    // initialize variable 
    h = a[1][0]-a[0][0];
    r=(f-a[n-1][0])/h;
    y=a[n-1][1];
    d=r ;  fact=1; j=2;
    // Calculation
    for(j=2;j<n+1;j++)
    {
        y=y+d*a[n-1][j]/fact;
        d=d*(r+j-1);
        fact=fact*j;
    }
    //output
    printf("For the value of x = %0.3f \nThe value is %0.3f.",f,y);
}