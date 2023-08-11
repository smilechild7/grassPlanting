#include <iostream>

using namespace std;


int changeCount(int N,int M,char arr[50][50]){
    int a = N-7;
    int b = M-7;
    int cnt = 0;
    int min = 64;
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            for (int k=0; k<8; k++) {
                for (int r=0; r<8; r++) {
                    if ((k+r)%2==0 && arr[i+k][j+r]=='W') {
                        cnt+=1;
                    } else if ((k+r)%2==1 && arr[i+k][j+r]=='B'){
                        cnt+=1;
                    }
                }
            }
            if (cnt > 32) {
                cnt = 64-cnt;
            }
            if (min > cnt){
                min = cnt;
            }
            cnt=0;
        }
    }
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    char arr[50][50]={'O'};
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    cout << changeCount(N,M,arr);
}