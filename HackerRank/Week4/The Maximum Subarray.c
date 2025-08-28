#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);


int* maxSubarray(int arr_count, int* arr, int* result_count) {
int* result = malloc(2 * sizeof(int));
int max_current = arr[0];
int max_global = arr[0];
for(int i=1;i<arr_count;i++){
    max_current = (arr[i] > max_current + arr[i]) ? arr[i] : max_current + arr[i];
    if(max_current > max_global){
        max_global = max_current;
    }
}
    int non_contig_sum = 0;
    int max_element = arr[0];
    for(int i=0;i<arr_count;i++){
        if(arr[i] > 0){
            non_contig_sum += arr[i];
        }
        if(arr[i] > max_element){
            max_element = arr[i];
            
        }
        
    }
    if(non_contig_sum == 0){
        non_contig_sum = max_element;
    }
    
    result[0] = max_global;
    result[1] = non_contig_sum;
    *result_count = 2;
    return result;
}

int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        int* arr = malloc(n * sizeof(int));
        for(int i =0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int result_count;
        int* result = maxSubarray(n,arr,&result_count);
        
        for(int i =0;i<result_count;i++){
            printf("%d",result[i]);
            if(i != result_count -1){
                printf(" ");
            }
        }
        printf("\n");
        free(arr);
        free(result);
    }
    return 0;
}
    
