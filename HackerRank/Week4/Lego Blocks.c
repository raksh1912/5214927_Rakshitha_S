#include<stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAXN 1000

long long T[MAXN+1] [MAXN+1];
long long B[MAXN+1], G[MAXN+1];

long long modpow(long long base, int exp){
    long long result = 1;
    base %= MOD;
    while(exp >0){
        if(exp & 1) result = (result * base) % MOD;
        base = (base * base)% MOD;
        exp >>= 1;
    }
    return result;
}

void init(){
    T[1][0] = 1;
    for(int j=1;j<= MAXN;j++){
        T[1][j] = 0;
        if(j>=1) T[1][j] += T[1][j-1];
        if(j>=2) T[1][j] += T[1][j-2];
        if(j>=3) T[1][j] += T[1][j-3];
        if(j>=4) T[1][j] += T[1][j-4];
        T[1][j] %= MOD;
    }
    for(int i=2;i<=MAXN;i++){
        for(int j=1;j<=MAXN;j++){
            T[i][j] = modpow(T[1][j],i);
        }
    }}
    int main(){
        init();
        
        int nbOfOps;
        scanf("%d",&nbOfOps);
        
        while(nbOfOps--){
            int n,m;
            scanf("%d %d",&n,&m);
            
            B[1] = 0;
            G[1] = T[n][1];
            
            for(int j=2;j<=m;j++){
                B[j] = 0;
                for(int k=1;k<j;k++){
    B[j] = (B[j]+ (T[n][j-k] * G[k])% MOD)% MOD;
                }
                G[j]  = (T[n][j] - B[j] + MOD) % MOD;
            }
            printf("%lld\n",G[m]);
        }
        return 0;
    }
