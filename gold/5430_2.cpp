#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for(int t=0; t<T; t++){
        // AC 언어
        string AC; cin >> AC;
        queue <char> q; // R와 D의 배열이 들어가는 큐
        bool boolean = true;
        int front=0, back=0; // 앞과 뒤에서 몇개를 뺄 지 정함
        int cnt=0; // 몇 번 뒤집을 건지 
        for (int j=0; j<AC.length(); j++) {
            if (AC[j] == 'R') {
                boolean = !boolean;
                cnt+=1;
            }
            if (AC[j] == 'D') {
                if (boolean) {
                    front+=1;
                } else {
                    back+=1;
                }
            }
            q.push(AC[j]);
        } 

        // 숫자배열 받기
        int n; cin >> n;
        string str;
        cin >> str;
        vector<string> v;
        if (n!=0){
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
            }
        } else {
            
        }
        

        // 결과 출력
        if (n < front + back) {
            cout << "error\n";
            continue;
        } else if (n == front+back) {
            cout << "[]\n";
            continue;
        }
        if (v.size()>0) {
            if (cnt%2==0){
                cout << '[';
                for (int j=front; j<v.size()-1-back; j++) {
                    cout << v[j] << ',';
                }
                cout << v[v.size()-back-1] << ']' << "\n";
            } else if (cnt%2==1) {
                cout << '[';
                for (int j=v.size()-back-1; j>front; j--) {
                    cout << v[j] << ',';
                }
                cout << v[front] << ']' << "\n";
            }
            
        } else {
            cout <<"[]\n";
        }


    }

}
