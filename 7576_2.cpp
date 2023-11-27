#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;

void update(int t, int i, int j, vector<vector<int>>& arr) {
    if (arr[i][j]==t) {
        if (arr[i+1][j]==0 || arr[i+1][j]>t+1){
            arr[i+1][j] = t+1;
            update(t+1,i+1,j,arr);
        }
        if (arr[i-1][j]==0 || arr[i-1][j]>t+1){
            arr[i-1][j] = t+1;
            update(t+1,i-1,j,arr);
        }
        if (arr[i][j-1]==0 || arr[i][j-1]>t+1){
            arr[i][j-1] = t+1;
            update(t+1,i,j-1,arr);
        }
        if (arr[i][j+1]==0 || arr[i][j+1]>t+1){
            arr[i][j+1] = t+1;
            update(t+1,i,j+1,arr);
        }
    }
    return; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N; // M 가로 N 세로
    vector<vector<int>> arr(N + 2, vector<int>(M + 2, -3)); // 토마토 배열 (테두리를 포함한) 
    queue <int> q1,q2;
    
    for (int i=1; i<=N; i++) { // 테두리만 -3로 남음
        for (int j=1; j<=M; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==1){
                q1.push(i);
                q2.push(j);
            }
        }
    }
    int t = 1;
    while(!q1.empty()){
        if (arr[q1.front()][q2.front()]==1){
            update(t,q1.front(),q2.front(),arr);
            q1.pop(); q2.pop();
        }
    }
            
    int max = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++){
            if (arr[i][j]==0){
                cout << -1;
                return 0;
            } else {
                if (arr[i][j]>max){
                    max = arr[i][j];
                }
            }
        }
    }
    cout << max-1;
    return 0;
}
