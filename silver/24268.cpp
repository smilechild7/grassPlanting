#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int get10Num(vector <int>& v, int d) {
    int res;
    for (int i=0; i<d; i++) {
        int k = pow (d,d-1-i);
        res+= v[i]*k;
    }
    return res;
}

int isin (vector <int> v, int n) {
    for (int i=0; i<v.size(); i++) {
        if (v[i]==n) {
            return 0;
        }
    }
    return 1;
}

void getMemo(vector <int>& v2, int d, int M) {
    if (!v2.empty()){
        if (v2[0] == 99){
            return;
        }
    }
    if (v2.size()<d) {
        for (int i=0; i<d; i++) {
            if (isin(v2,i+1)==1) {
                v2.push_back(i);
                getMemo(v2, d, M);
                v2.pop_back();
            }        
        }
    } else {
        int v2To10 = get10Num(v2,d);
        if (v2To10 > M) {
            cout << v2To10 << "\n";
            v2.clear();
            v2.push_back(99);
        }
    }

} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int d; cin >> d;
    vector <int> v1;
    int i=0;
    while (true){
        int k = pow(d,i);
        if (N < k) {
            break;
        }
        v1.push_back(N%k);
        i++;
    }
    reverse(v1.begin(),v1.end());
    
    if (v1.size() > d) {
        cout << -1 <<"\n";
    } else if (v1.size() < d) {
        vector <int> v3;
        v3.push_back(1);
        v3.push_back(0);
        for (int j=2; j<d; j++) {
            v3.push_back(j);
        }
        int res=0;
        for (int j=0; j<d; j++) {
            int p = pow(d,d-j-1);
            res+= p*v3[j];
        }
        cout << res << "\n";
    } else {
        vector <int> v2;
        int M = get10Num(v1,d);
        getMemo(v2,d,M);
    }
       
}