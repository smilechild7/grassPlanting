#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    if (N < 100) {
        cout << N <<"\n";
        return 0;
    } else {
        int res = 99;
        for (int i=100; i<=N; i++) {
            int a,b,c;
            a = i/100;
            b = (i%100)/10;
            c = i%10;
            if (a+c == 2*b && i!=1000) {
                res+=1;
            }
        }
        cout << res << "\n";
    }
}