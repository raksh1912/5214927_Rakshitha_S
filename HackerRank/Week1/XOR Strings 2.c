#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* strings_xor(char *s,char *t){
    int n = strlen(s);
    char *res = malloc(n +1);
    int i; 
    for (i =0;i<n;i++){
        if(s[i] == t[i])
        res[i] = '0';
        else
         res[i] = '1';
    }
    res[n] = '\0';
    return res;
    
}
int main()
{
    char s[10005], t[10005];
    scanf("%s",s);
    scanf("%s",t);
    printf("%s\n",strings_xor(s,t));
    return 0; 
}
