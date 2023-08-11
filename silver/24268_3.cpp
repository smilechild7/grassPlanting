#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int vectoNum(int d, vector <int>& v){
    int res=0;
    for (int i=0; i<d; i++) {
        res+=pow(d,d-1-i)*v[i];
    }
    return res;
}
void getVector(int N, int d, vector <int>& v){
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

int howMany(int d, int n, vector <int>& v){
    int cnt = 0;
    for (int i=0; i<d; i++){
        if (v[i]==n){
            cnt+=1;
        }
    }
    return cnt;
}

void makeNum(int d, vector <int>& v){
    for (int i=d-1; i>=0; i--){
        if (v[i]==d){
            v[i-1]=v[i-1]+1;
            for (int j=i; j<d; j++){
                v[j]=0;
            }
        }
    }
}

void zero(int d, int i, vector <int>& v){
    for (int j=i+1; i<d; i++){
        v[j]=0;
    }
}

void getNum(int d, vector <int>& v){
    bool boolean = true;
    while (boolean) {
        for(int i=d-1; i>=0; i--) {
            if (howMany(d,v[i],v)>1){
                if (v[i]==d-1){
                    v[i-1] = v[i-1] +1;
                    makeNum(d,v);
                    zero(d,i-1,v);
                    break;
                } else {
                    v[i] = v[i] +1;
                    zero(d,i,v);
                    break;
                }
            }
            if (i==0){
                boolean = false;
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
    if(min_10 > N){
        N = min_10;
    }
    if (N >= max_10) {
        cout << -1;
        return 0;
    } else {
        getVector(N+1,d,v);
        getNum(d,v);
        cout << vectoNum(d,v);
    }
    return 0;
}