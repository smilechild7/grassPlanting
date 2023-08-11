#include<cstdio>

int list[40];
int* ptr = &list[0];

int fibonacci(int n, int *ptr) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (*(ptr+n)!=0){
        return *(ptr+n);
    } else {
        *(ptr+n) = fibonacci(n-1,ptr) + fibonacci(n-2,ptr);
        return *(ptr+n);
    }
}


int main(){
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        for (int j=0;j<41;j++){
            list[j]=0;
        }
        int n;
        scanf("%d",&n);
        if (n==0){
            printf("%d %d\n",1,0);
        } else if (n==1){
            printf("%d %d\n",0,1);
        } else if (n==2){
            printf("%d %d\n",1,1);
        } else {
            fibonacci(n,ptr);
            printf("%d %d\n",list[n-1],list[n]);
        }
    }
}