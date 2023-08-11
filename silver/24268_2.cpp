#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void Ntod(int N, int d, vector <int>& v){
    for(int i=d-1; i>=0; i--){
        for(int j=d-1; j>=0; j--){
            if(pow(d,i)*j<=N){
                v.push_back(j);
                N-=pow(d,i)*j;
                break;
            }
        }
    }
}


int isOk(int d, vector <int>& v){
    for(int i=0; i<d; i++) {
        for (int j=i+1; j<d;j++) {
            if(v[i]==v[j]){
                return -1;
            }
        }
    }
    return 1;
}

void printResult(int N, int d, int min_10, int max_10, vector <int>& v){
    for (int i=N+1; i<max_10; i++) {
        Ntod(i,d,v);
        if (isOk(d,v)==1){
            cout << i;
            break;
        }
        v.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int d; cin >> d;
    vector <int> v;
    int min_10, max_10=0;
    min_10 = pow(d,d-1);

    for (int i=0; i<d; i++) {
        max_10 += i*pow(d,i);
    }
    if (N > max_10) {
        cout << -1;
        return 0;
    } else {
        printResult(N,d,min_10,max_10,v);
    }
    return 0;
}