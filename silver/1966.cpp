#include <iostream>
#include <queue>
using namespace std;



int isBiggest(int n, queue<int>& q) {
    while (!q.empty()) {
        if (q.front() > n) {
            return 0;
        } 
        q.pop();
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int i=0; i<T; i++){
        int N,M;
        cin >> N >> M;
        queue<int> q,Q;
        q = queue <int> ();
        int cnt1=0;
        int formation = M;
        
        for (int i=0; i<N; i++) {
            int num;
            cin >> num;
            q.push(num);
        }

        while (!q.empty()) {
            Q = q;
            if (isBiggest(q.front(),Q)==1){
                q.pop();
                cnt1+=1;
                if(formation==0){
                    cout << cnt1 << "\n";
                    break;
                } else {
                    formation-=1;
                }
            } else {
                q.push(q.front());
                q.pop();
                if(formation==0){
                    formation+=q.size()-1;
                } else {
                    formation-=1;
                }
            }
        }   
    }
}
