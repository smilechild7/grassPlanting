#include <iostream>

using namespace std;

int memo[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int isin (int n) {
    for (int i=0; i<8; i++) {
        if (memo[i]==n) {
            return 0;
        }
    }
    return 1;
}

void getMemo(int N, int M, int k) {
    if (k<M) {
        for (int i=0; i<N; i++) {
            if (isin(i+1)==1) {
                memo[k] = i+1;
                getMemo(N,M,k+1);
                memo[k] = 0;
            }        
        }
    } else {
        for (int i=0; i<M; i++) {
            cout << memo[i] << " ";
        }
        cout << "\n";
    }
} 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    int k = 0;
    getMemo(N,M,k);
}