#include<stdio.h>
int main()
{
    int n,j,i,p=0,sum;
    scanf("%d",&n);
    int a[n],b[100];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(j=1;j<=100;j++)
    {    
        for(i=0;i<n;i++)
        if(j==a[i])
        p++;
        b[j]=p;
        p=0;
        
    }
    for(i=1;i<=100;i++)
    {
        j=b[i]/2;
        sum=sum+j;
    }
    printf("%d",sum);
    return 0;
    }
