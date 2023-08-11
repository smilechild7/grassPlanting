#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool boolean = false;

int isin(int n, vector <int>& v) {
    for (int i=0; i<v.size(); i++) {
        if (n == v[i]){
            return -1;
        }
    }
    return 1;
}

void getVect(int k, int d, vector <int>& v,int N){
    if (boolean){
        return;
    }
    if (k<d){
        for (int i=0; i<d; i++){
            if(isin(i,v)==1){
                v.push_back(i);
                getVect(k+1,d,v,N);
                v.pop_back();
            }
        }
    } else if (k==d) {
        if (v[0]!=0){
            int n = 0;
            for(int i=0; i<d; i++) {
                n+=pow(d,d-1-i)*v[i];
            }
            if (N<n) {
                cout << n;
                boolean = true;
            }
        }
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
    
    if (N >= max_10) {
        cout << -1;
        return 0;
    } else {
        getVect(0,d,v,N);
    }
    return 0;
}