#include<cstdio>

int main(){
    int T, N, K;
    scanf("%d", &T);
    for (int i=0;i<T;i++){
        scanf("%d %d", &N, &K);
        int D[N];
        for (int j=0;j<N;j++){
            scanf("%1d",&D[j]);
        }
        for (int j=0;j<N;j++){
            printf("%d ",D[j]);
        }
        
    }

}