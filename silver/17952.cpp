#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int minute[1000000];
    for (int i=0; i<1000000; i++){
        minute[i] = 0;
    }
    stack <int> score;
    int N, total, A, T;
    total = 0;
    cin >> N;
    for (int i=N; i>0; i--) {
        int j;
        j = N-i; 
        
        if (N==1) {
            cin >> A >> T;
            score.push(A);
            minute[j] = T;
            minute[j] -= 1;
        } else {
            if (!score.empty() && minute[j]==1){
                total += score.top();
                score.pop();
            } 
            if(minute[j]>1){
                minute[j] -=1;
            }
        }
    }
    cout << total << "\n";
    return 0;
}