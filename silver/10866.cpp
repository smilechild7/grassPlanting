#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    deque <int> s;
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        string S;
        int n;
        cin >> S;
        if (S == "push_back") {
            cin >> n;
            s.push_back(n);
        } else if ( S == "push_front") {
            cin >> n;
            s.push_front(n);
        } else if (S == "front") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.front() <<"\n";
            }
        } else if (S == "back") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.back() <<"\n";
            }
        } else if (S == "size") {
            cout << s.size() << "\n";
        } else if (S == "pop_front") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.front() <<"\n";
                s.pop_front();
            }
        } else if (S == "pop_back") {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << s.back() <<"\n";
                s.pop_back();
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
