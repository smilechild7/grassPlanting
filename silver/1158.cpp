#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    cout << "<";
    queue <int> q;
    for (int i=0; i<N; i++) {
        q.push(i+1);
    }
    while (true) {
        if (q.size()!=0){
            for (int i=0; i<K-1; i++) {
            int f = q.front();
            q.pop();
            q.push(f);
            }
            if (q.size()==1){
                cout << q.front() << ">";
                q.pop();
            } else {
                cout << q.front() << ", ";
                q.pop();
            }
            
        } else {
            break;
        }
    }
}