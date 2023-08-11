#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector <int> v;
    for (int i=0; i<N; i++) {
        int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());

    for (int i=N-1; i>=0; i--) {
        cout << v[i] << "\n";
    }

}