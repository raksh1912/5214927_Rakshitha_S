#include<stdio.h>
int main(){
    int num,i;
     scanf("%d",&num);
    int arr[num];
    float p=0,n=0,z=0;
   for( i=0;i<num;i++){
    scanf("%d",&arr[i]);
    if(arr[i]>0)
    p++;
    else if(arr[i]<0)
    n++;
    else
    z++;
   }
   printf("%.6f\n%.6f\n%.6f",p/num,n/num,z/num);
   return 0;
}
