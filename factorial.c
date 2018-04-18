#include<stdio.h>
#include<math.h>
void main()
{
    //clrscr();
    printf("Enter a Number to Find Factorial: ");
    fact();
    getch();
}
fact()
{
    int i,fact=1,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        fact=fact*i;
    }
    printf("\nFactorial of a Given Number is: %d ",fact);
    return fact;
}
