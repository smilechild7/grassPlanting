#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int T;
    cin >> T;
    cin.ignore();
    for (int i=0; i<T; i++){
        stack<char> c;
        string sentence;
        getline(cin, sentence);
        for (int j=0; j<sentence.size();j++){
            if(sentence.size()-1==j){
                c.push(sentence[j]); 
                while(!c.empty()){
                    cout << c.top();
                    c.pop();
                }
            } else if (sentence[j]==' '){
                while(!c.empty()){
                    cout << c.top();
                    c.pop();
                }
                cout << " ";
            } else {
                c.push(sentence[j]);                
            }
        }
        cout << "\n";
    }

}