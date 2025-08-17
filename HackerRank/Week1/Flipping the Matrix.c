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


int flippingMatrix(int matrix_rows, int matrix_columns, int** matrix) {
    int n = matrix_rows / 2;
    int sum = 0;
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int a = matrix[i][j];
            int b = matrix[i][matrix_columns - 1 - j];
            int c = matrix[matrix_rows - 1 - i][j];
            int d = matrix[matrix_rows - 1 - i][matrix_columns - 1 - j];

            int maxVal = a;
            if (b > maxVal) maxVal = b;
            if (c > maxVal) maxVal = c;
            if (d > maxVal) maxVal = d;

            sum += maxVal;
        }
    }

    return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	int size = 2*n;
	int **matrix = (int **)malloc(size * sizeof(int *));
	int i,j;
	for(i = 0;i<size;i++){
		matrix[i] = (int *)malloc(size *sizeof(int));
		for(j =0; j<size;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	
	int result = flippingMatrix(size,size,matrix);
	printf("%d\n",result);
	for(i=0;i<size;i++){
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
