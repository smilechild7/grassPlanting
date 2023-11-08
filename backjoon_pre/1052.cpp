#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,K,res;
    cin >> N >> K;

    if (N<=K) {
        cout << 0;
        return 0;
    }
  

    for (int i=0; i<K-1; i++) {
        int T=1;
        while (2*T<N) {
            T*=2;
        }
        if (N>1) {
            N-=T;
        }
    }
    if (N<=2) {
        cout << 0;
        return 0;
    }
    int t=1;
    while (t<N) {
        t*=2;
    }
    res = t-N;
    cout << res;
    return 0;
}
