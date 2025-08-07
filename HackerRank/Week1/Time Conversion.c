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


char* timeConversion(char* s) {
    int hr = atoi(strtok(s,":"));
    int min = atoi(strtok(NULL ,":"));
    int sec = atoi(strtok(NULL,""));
    
    char ampm[3];
    ampm[0] = s[8];
    ampm[1] = 'M';
    ampm[2] = '\0';
    char *time = malloc(128*sizeof(char));
    
    if(strcmp(ampm,"AM")== 0 && hr == 12)
     sprintf(time,"00:%.2d:%.2d",min,sec);
     else if(strcmp(ampm,"AM")==0)
     sprintf(time,"%.2d:%.2d:%.2d",hr,min,sec);
     else if(strcmp(ampm,"PM")==0){
     if(hr!=12)
     hr = hr+12;
     sprintf(time,"%.2d:%.2d:%.2d",hr,min,sec);
     }
     return time;
     
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
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
