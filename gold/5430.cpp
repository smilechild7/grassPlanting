#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        string AC;
        cin >> AC;
        queue <char> q;
        for (int j=0; j<AC.length(); j++) {
            q.push(AC[j]);
        } // q : RD 큐
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<string> v;
        if (n!=0) {
           string charsToRemove = "[]";
        size_t start = str.find_first_not_of(charsToRemove);
        if (start != std::string::npos) {
            str.erase(0, start);
        }
        size_t end = str.find_last_not_of(charsToRemove);
        if (end != std::string::npos) {
            str.erase(end + 1);
        }

        istringstream ss(str);
        string strBuffer;
        
        stack <int> numStack;
        while (getline(ss, strBuffer, ',')) {
            v.push_back(strBuffer);
        } // v : 숫자 배열
        

        stack <char> S;
        while (!q.empty()) {
            if (S.empty()) {
                S.push(q.front());
                q.pop();
            } else if (S.top()=='R') {
                if (q.front() == 'R') {
                    S.pop();
                    q.pop();     
                } else if (q.front() == 'D') {
                    S.push(q.front());
                    q.pop();
                }
            } else {
                S.push(q.front());
                q.pop();
            }
        }
        stack <char> Q;
        while (!S.empty()){
            Q.push(S.top());
            S.pop();
        }
        bool boolean = true;
        while (!Q.empty()) {
            if (v.size()==0 && Q.top() =='D'){
                cout << "error" << "\n";
                boolean = false;
                break;
            }
            if (Q.top() == 'R') {
                reverse(v.begin(),v.begin()+n);
                Q.pop();
            } else if (Q.top() == 'D') {
                v.erase(v.begin());
                Q.pop();
            }
        }
        if (boolean){
            cout << '[';
            for (int j=0; j<v.size()-1; j++) {
                cout << v[j] << ',';
            }
            cout << v[v.size()-1] << ']' << "\n";
        }
        } else {
            while (!q.empty()) {
                if(q.front() == 'D'){
                    cout << "error\n";
                    break;
                }
                q.pop();
            }
        }
        
        
        
    }
}