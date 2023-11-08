#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void){
    queue<int> q;
    int N; cin >> N;
    string ans;
    for(int i=0; i<N; i++){
        cin >> ans;
        if(ans=="push"){
            int x; cin >> x;
            q.push(x);
        }else if(ans=="pop"){
            if(!q.empty()){
                cout << q.front() << endl;
                q.pop();
            }else{
                cout << -1 << endl;
            }
        }else if(ans=="size"){
            cout << q.size() << endl;
        }else if(ans=="empty"){
            cout << q.empty() << endl;
        }else if(ans=="front"){
            if(!q.empty()){
                cout << q.front() << endl;
            }else{
                cout << -1 << endl;
            }
        }else if(ans=="back"){
            if(!q.empty()){
                cout << q.back() << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }
}
