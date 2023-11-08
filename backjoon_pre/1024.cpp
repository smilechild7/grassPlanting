#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    int L;
    cin >> N >> L;
    
    while (L <= 100) {
        long long n = N / L; // Middle value
        long long a1; // Initial value
        
        if (L % 2 == 0) {
            // For even L, we want the middle two values
            a1 = n - L / 2 + 1;
        } else {
            // For odd L, we want the middle value
            a1 = n - L / 2;
        }
        
        if (a1 >= 0 && L * a1 + L * (L - 1) / 2 == N) {
            // Check if the sequence sums to N and a1 is non-negative
            for (int i = 0; i < L; i++) {
                cout << a1 + i << " ";
            }
            return 0;
        }
        
        L += 1;
    }
    
    cout << -1; // If no sequence is found
    return 0;
}
