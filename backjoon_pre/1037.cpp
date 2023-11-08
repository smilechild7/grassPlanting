#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector <int> v;
    int N; cin >> N;

    for (int i=0; i<N; i++) {
        int n; cin >> n;
        v.push_back(n);
    }

    sort(v.begin(),v.end());
    long a,b,k;
    if (N%2==1) {
        k = v[N/2];
        cout << k*k;
    } else {
        a = v.front();
        b = v.back();
        cout << a*b;
    }
    return 0;
}