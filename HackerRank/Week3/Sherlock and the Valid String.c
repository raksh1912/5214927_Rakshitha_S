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


char* readLine();

 static int cmp_int(const void *a, const void *b){
    return (*(const int*)a - *(const int*)b);
 }   
    
char* isValid(char* s){
    static char YES[] = "YES";
    static char NO[] = "NO";

    int counts[26] = {0};
    for(char *p = s; *p; ++p){
        if(*p >= 'a' && *p <= 'z') counts[*p - 'a']++;
    }
    

    int freq[26];
    int c =0;
    for(int i=0;i<26;i++){
        if(counts[i] > 0) freq[c++] = counts[i];
    }
       if(c==0)
       return YES;


   qsort(freq, c,sizeof(int), cmp_int);
   int first = freq[0];
   int last = freq[c-1];
   
   if(first == last) return YES;

if(c>= 2 && first ==1 && freq[1] == last)
return YES;

if(c>=2 && last == freq[c-2] + 1 && freq[0] == freq[c-2])
return YES;
return NO;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readLine();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readLine() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
