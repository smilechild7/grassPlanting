#include <iostream>

using namespace std;

void hanoi(int N, int a, int b, int c){
    if (N>0) {
        hanoi(N-1,a,c,b);
        cout << a << " " << b << "\n";
        hanoi(N-1,c,b,a);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,K;
    cin >> N;
    K = 1;
    for (int i=0; i<N; i++){
        K*=2;
    }
    K-=1;
    cout << K << "\n";
    hanoi(N,1,3,2);
}