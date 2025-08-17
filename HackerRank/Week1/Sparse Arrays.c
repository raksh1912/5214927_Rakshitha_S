#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_LEN 20

void matchingStrings(char strings[][MAX_LEN], int n, char queries[][MAX_LEN], int q, int results[]) {
   int i;
    for (i = 0; i < q; i++) {
        int count = 0,j;
        for (j = 0; j < n; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        results[i] = count;
    }
}

int main() {
    int n, q,i;
    char strings[MAX][MAX_LEN];
    char queries[MAX][MAX_LEN];
    int results[MAX];

    // Read number of strings
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    // Read number of queries
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%s", queries[i]);
    }

    // Find matching counts
    matchingStrings(strings, n, queries, q, results);

    // Print results
    for (i = 0; i < q; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}
