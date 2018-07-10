#include<stdio.h>
#include<conio.h>
main()
{
    int a[]={2,3,5,4,7,8,9};
    int b[]={2,3,5,7};
    int i,j,n1=7,n2=4,flag=0,k,flag1=0;
    for(i=0;i<=n1-n2;i++)
    {
        flag1=0;
        if(a[i]==b[0])
        {
            k=i+1;
            for(j=1;j<n2;j++)
            {
                if(b[j]!=a[k])
                {
                    flag1=1;
                    break;
                }
                k++;
            }
            printf("\nflag1=%d\nj=%d\nk=%d",flag1,j,k);
            if(flag1==0)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
    {
        printf("\narray 2 is subsequence of array 1");
    }
    else
    {
        printf("\narray 2 is not subsequence of array 1");
    }
}

