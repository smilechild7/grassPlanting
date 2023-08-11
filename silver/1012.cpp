#include<cstdio>

int num = 0;
int farm[52][52];

void fire(int i,int j){
    if (farm[i][j]==1 || farm[i][j]==2) {
        if (farm[i+1][j]==1) {
            farm[i+1][j]=2;
            fire(i+1,j);
        }
        if (farm[i][j+1]==1) {
            farm[i][j+1]=2;
            fire(i,j+1);
        }
        if (farm[i-1][j]==1) {
            farm[i-1][j]=2;
            fire(i-1,j);
        }
        if (farm[i][j-1]==1) {
            farm[i][j-1]=2;
            fire(i,j-1);
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        num = 0;
        int m,n;
        int M,N,K;
        scanf("%d %d %d",&M,&N,&K);
        for(int j=0; j<52;j++){
            for(int k=0; k<52; k++){
                farm[j][k] = 0;
            }
        }
        for(int j=0; j<K; j++){
            scanf("%d %d",&m,&n);
            farm[m+1][n+1] = 1;
        }
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (farm[i+1][j+1]==1) {
                   num+=1;
                   fire(i+1,j+1);
                }
            }
        }
        printf("%d\n",num);
    }
}