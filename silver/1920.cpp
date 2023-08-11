#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
void func (vector<int>& v, long long int n) {
    int str=0, end=v.size()-1;
    while (str<=end) {
        int mid = str + (end-str)/2;
        if (n > v[mid]) {
            str = mid+1;
        } else if (n == v[mid]) {
            cout << 1 << "\n";
            return;
        } else if (n < v[mid]) {
            end = mid-1;
        }
    }
    cout << 0 << "\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    for (int i=0; i<N; i++) {
        long long int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());

    int M; cin >> M;
    for (int i=0; i<M; i++) {
        long long m; cin >> m;
        func(v,m);
    }
}