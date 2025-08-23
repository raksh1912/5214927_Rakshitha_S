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



char** detonate(int r,int c,char** grid){
char** res = malloc(r * sizeof(char*));
for(int i=0;i<r;i++){
    res[i] = malloc(c +1);
    memset(res[i],'O',c);
    res[i][c] = '\0';
}  
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(grid[i][j] == 'O'){
            res[i][j] = '.';
            for(int d=0;d<4;d++){
                int ni = i+dr[d],nj =j+dc[d];
                if(ni >=0 && ni <r && nj >= 0 && nj <c){
                    res[ni][nj] = '.';
                }
            }
        }
    }
}
return res;
}

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
int r = grid_count;
int c = strlen(grid[0]);

*result_count = r;

if(n==1){
    char** res = malloc(r * sizeof(char*));
    for(int i=0; i<r;i++){
        res[i] = strdup(grid[i]);
        
    }
    return res;
}

if(n%2 == 0){
    char** res = malloc(r * sizeof(char*));
    for(int i=0; i<r;i++){ 
        res[i] = malloc(c+1);
        memset(res[i], 'O',c);
        res[i][c] = '\0';
        
}
return res;
}

char** first = detonate(r,c,grid);
if(n % 4 == 3){
    return first;
    
}
else{
    char** second = detonate(r,c,first);
    
    for(int i=0;i<r;i++)
    free(first[i]);
    free(first);
    
    return second;
}
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int r = parse_int(*(first_multiple_input + 0));

    int c = parse_int(*(first_multiple_input + 1));

    int n = parse_int(*(first_multiple_input + 2));

    char** grid = malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int result_count;
    char** result = bomberMan(n, r, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
