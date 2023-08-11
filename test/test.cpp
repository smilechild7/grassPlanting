#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue <char> q;

    string s;
    cin >> s;
    for (int j=0; j<s.length(); j++) {
            q.push(s[j]);
        }
    cout << q.front();
}