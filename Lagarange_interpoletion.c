#include<stdio.h>
int main()
{
    float x[20],y[20],f,sum,temp;
    int i,j,n;
    printf("Enter the value of n:"); //Read the length of the table from user
    scanf("%d",&n);
    printf("Enter the values of x:"); // read the elements of the x coloumn.
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);
    printf("Enter the values of y:"); // read the elements of the y coloumn.
    for(j=0;j<n;j++)
        scanf("%f",&y[j]);
    printf("Enter the value of x for interpolation:"); //Take the input from user value of x 
    scanf("%f",&f);
    sum=0; temp= 1;
    for (i=0;i<n;i++)
    {
        temp=1;
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                temp=temp*(f-x[j])/(x[i]-x[j]);
            }
        }
        sum = sum + temp*y[i];
    }
    printf("For the value of x = %0.3f \nThe value is %0.3f.",f,sum);
}