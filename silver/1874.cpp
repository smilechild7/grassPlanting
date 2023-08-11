#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue <int> q; // 12345678...
    queue <char> printq; // ++++-...
    stack <int> s;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        q.push(i+1);
    }
    int numList[n];
    for (int i=0; i<n; i++) {
        cin >> numList[i];
    }
    for (int i=0; i<n; i++) {
        if (s.empty()) {
            s.push(q.front());
            printq.push('+');
            q.pop();
            while (numList[i] > s.top()) {
                s.push(q.front()); 
                printq.push('+');
                q.pop();
            }
            s.pop();
            printq.push('-');
        } else if (s.top() > numList[i]) {
            cout << "NO";
            return 0; // good
        } else if (s.top() == numList[i]) {
            s.pop();
            printq.push('-');
        } else if (s.top() < numList[i]) {
            while (s.top() < numList[i]){
                s.push(q.front());
                printq.push('+');
                q.pop();
            }
            s.pop();
            printq.push('-');
        }
    }
      
    while (!printq.empty()) {
        cout << printq.front() << "\n";
        printq.pop();
    }
    return 0;
}