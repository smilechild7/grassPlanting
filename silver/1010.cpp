#include<cstdio>


int memo[31][31];

int combination(int N, int M){
    if (memo[M][N]!=-1){
        return memo[M][N];
    } else if (M==N || N==0) {
        memo[M][N] = 1;
        return 1;
    } else {
        int res = combination(N-1,M-1)+combination(N,M-1); 
        memo[M][N] = res;
        return res;
    }
}

int main(void){
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; i++){
        int N,M;
        scanf("%d %d",&N,&M);
        for (int i=0; i<(M+1); i++){
            for (int j=0; j<(N+1); j++){
                memo[i][j]=-1;
            }
        }
        int caseNum = combination(N,M);
        printf("%d\n",caseNum);  
    }
}

