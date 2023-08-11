#include<stdio.h>
int j=0;
int checkPrimeNum(int num, int* ptr){
    if(num==2){
        *(ptr+j)=num;
        j+=1;
        return 1;
    } else if(num==1){
        return 0;
    }
    for(int i=2;i<num;i++){
        if (num%i==0){
            return 0;
        } 
    }
    *(ptr+j)=num;
    j+=1;
    return 1;
}

int main(void){
    int M,N;
    scanf("%d",&M);
    scanf("%d",&N);
    int arr[N-M+1];
    int* ptr = &arr[0];
    for (int i=0; i<N-M+1;i++){
        arr[i]=0;
    }
    for (int i=0; i<N-M+1;i++){
        checkPrimeNum(M+i,ptr);
    }
    int sum = 0;
    for (int i=0; i<N-M+1;i++){
        sum+=arr[i];
    }
    if (arr[0]==0){
        printf("%d\n",-1);
    } else {
    printf("%d\n",sum);
    printf("%d",arr[0]);
    }
}