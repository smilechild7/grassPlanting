#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void){
    string str; cin >> str;
    int M; cin >> M;
    list<char> l;
    list<char>::iterator it;
    for(int i=0; i<str.length(); i++){
        l.push_back(str[i]);
    }
    it = l.end();
    char ans;
    for(int i=0; i<M; i++){
        cin >> ans;
        if(ans == 'L'){
            if(it!=l.begin()){
                it--;
            }
        }else if(ans == 'D'){
            if(it!=l.end()){
                it++;
            }
        }else if(ans == 'B'){
            if(it!=l.begin()){
                it--;
                it = l.erase(it);
            }
        }else if(ans == 'P'){
            char c;
            cin >> c;
            l.insert(it,c);
        }
    }
    for(it=l.begin();it!=l.end();it++){
        cout<<*it;
    }
    cout<<endl;
    return 0;
}