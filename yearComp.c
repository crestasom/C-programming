#include<stdio.h>
#include<conio.h>
main(){
    int startYr=2001,currentYr,nearestStartLeap=2004,nearestEndLeap,i,flag,leapCount,nonLeapCount,dayCount,actualDay;
    printf("Enter Current Year:");
    scanf("%d",&currentYr);
    for(i=currentYr;i>nearestStartLeap;i--)
    {
        flag=0;
        if(i%4==0)
        {
            if(i%100==0)
            {
                if(i%400==0)
                {
                    flag=1;
                }else
                {
                    flag=0;
                }
            }
            else
            {
                flag=1;
            }
        }
        else
        {
            flag=0;
        }
        if(flag==1)
        {
            nearestEndLeap=i;
            break;
        }
    }
    printf("\n%d",nearestEndLeap);
    leapCount=(nearestEndLeap-nearestStartLeap)/4;
    nonLeapCount=currentYr-1-leapCount;
    dayCount=nonLeapCount+leapCount*2;
    actualDay=dayCount%7;
    printf("\n%d",actualDay);
    getch();
}