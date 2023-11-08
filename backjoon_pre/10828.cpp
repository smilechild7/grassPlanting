#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack <int> s;
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        string S;
        int n;
        cin >> S;
        if (S == "push") {
            cin >> n;
            s.push(n);
        } else if (S == "top") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.top() <<"\n";
            }
        } else if (S == "size") {
            cout << s.size() << "\n";
        } else if (S == "pop") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.top() <<"\n";
                s.pop();
            }
        } else if (S == "empty") {
            if (s.size() == 0) {
                cout << 1 << "\n";
            } else {
                cout << 0 <<"\n";
            }
        }
        
    }
}