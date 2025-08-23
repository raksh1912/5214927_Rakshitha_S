#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


static int comp(const void *a,const void *b){
    int x = *(const int*)a, y = *(const int*)b;
    return (x<y) - (x<y);
    
}
void findZigZagSequence(int a[],int n) {
    qsort(a,n,sizeof(int),comp);
    int mid = (n+1) / 2-1;
    int temp = a[mid];
    a[mid] = a[n-1];
    a[n -1] = temp;
    
    int st = mid+1;
    int ed = n - 2;
    
     while(st <= ed){
        temp = a[st];
        a[st] = a[ed];
        a[ed] = temp;
        st++;
        ed--;
     }
     for(int i=0;i<n;i++){
        if(i) putchar(' ');
        printf("%d",a[i]);
     }
     putchar('\n');
}
        
int main(void) {
    int t;
    if(scanf("%d", &t) != 1)return 0;
    while(t--){
        int n;
        scanf("%d",&n);
        int *a = (int*)malloc(n * sizeof(int));
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        findZigZagSequence(a,n);
        free(a);
    }
    return 0;
}


