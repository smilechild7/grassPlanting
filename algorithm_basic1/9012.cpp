#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++){
        int left=0, right=0;
        string str;
        bool end = false;
        cin >> str;
        int len = str.length();
        for (int k=0; k<len; k++){
            if (str[k]=='('){
                left +=1;
            } else {
                right +=1;
            }
            if(left < right){
                cout << "NO" << endl;
                end = true;
                break;           
            }
        }
        if (left==right&&!end){
            cout << "YES" << endl;
        } else if (!end){
            cout << "NO" << endl;
        }
    }
}