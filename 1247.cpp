#include <iostream>

using namespace std;

int main() {

    for (int i=0; i<3; i++) {
        int n;
        int a=0;
        cin >> n;
        long long int sum=0;
        for (int j=0; j<n; j++) {
            long long int k;
            cin >> k;
            if (k>922337203685477 || k < -922337203685477){
                a+=k/922337203685477;
                sum+=k%922337203685477;
            } else {
                sum+=k;
            }
            if (sum > 922337203685477 || sum < -922337203685477) {
                a+=sum/922337203685477;
                sum = sum%922337203685477;
            }
        
        }
        if (a > 0){
            cout << "+" << "\n";
        } else if (a<0) {
            cout << "-" << "\n";
        } else {
            if (sum > 0.1){
                cout << "+" << "\n";
            } else if (sum <-0.1) {
                cout << "-" << "\n";
            } else {
                cout << "0" << "\n";
            }
        }
    }
}