#include <iostream>
#include <string>
using namespace std;

int tf=0;

void isAKARAKA(string str, int len) {
    for (int i=0; i<len/2; i++) {
        if (str[i]==str[len-1-i]) {
            tf+=0;
        } else {
            tf+=1;
        }
    }
    if(tf==0 && len>1){
        isAKARAKA(str,len/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;

    int len;
    len = str.length();
    isAKARAKA(str,len);
    if (tf == 0){
        cout << "AKARAKA";
    } else {
        cout << "IPSELENTI";
    }
}