#include <iostream>
#include <vector>

using namespace std;

int N,M;

int update(int t, int M, int N, vector<vector<int>>& arr) {
    int isUpdate = -1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (arr[i][j]==t) {
                if (arr[i+1][j]==0){
                    arr[i+1][j] = t+1;
                    isUpdate = 1;
                }
                if (arr[i-1][j]==0){
                    arr[i-1][j] = t+1;
                    isUpdate = 1;
                }
                if (arr[i][j-1]==0){
                    arr[i][j-1] = t+1;
                    isUpdate = 1;
                }
                if (arr[i][j+1]==0){
                    arr[i][j+1] = t+1;
                    isUpdate = 1;
                }
            }
        }
    }
    return isUpdate;
} 

int isZero(int M, int N, vector<vector<int>>& arr) {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (arr[i][j]==0){
                return -1;
            }
        }
    } 
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N; // M 가로 N 세로
    vector<vector<int>> arr(N + 2, vector<int>(M + 2, -3)); // 토마토 배열 (테두리를 포함한) 
    int size = N*M;
    
    for (int i=1; i<=N; i++) { // 테두리만 -3로 남음
        for (int j=1; j<=M; j++) {
            cin >> arr[i][j];
        }
    }
    int k = 1;
    for (int i=1; i<size; i++) {
        k = update(i,M,N,arr);
        if (k==-1){
            if (isZero(M,N,arr)==-1){
                cout << -1;
            } else {
                cout << i-1;
            }
            break;
        }
    }
}
