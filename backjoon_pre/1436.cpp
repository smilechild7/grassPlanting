#include <iostream>
#include <string>
using namespace std;

int isNum(int num) {
    string str = to_string(num);
    int count = 0;
    for (int i=0; i<str.length()-2;i++){
        if (str[i]=='6' && str[i+1]=='6' && str[i+2]=='6') return 1;
    }
    return 0;
}

void end(int n){
    int k = 0;
    int num = 100;   
    while (true){
        if (k!=n) {
            if(isNum(num)==1) k+=1;
        } else {
            cout << num-1;
            break;
        }
        num+=1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    end(n);
}