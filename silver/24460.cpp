#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int specialPrize(vector<vector<int>>& chair) {
    int n = chair.size();
    if (n > 2) {
        int half = n / 2;
        vector<vector<int>> chair1(half, vector<int>(half));
        vector<vector<int>> chair2(half, vector<int>(half));
        vector<vector<int>> chair3(half, vector<int>(half));
        vector<vector<int>> chair4(half, vector<int>(half));

        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                chair1[i][j] = chair[i][j];
                chair2[i][j] = chair[i+half][j];
                chair3[i][j] = chair[i][j+half];
                chair4[i][j] = chair[i + half][j + half];
            }
        }

        int a1 = specialPrize(chair1);
        int a2 = specialPrize(chair2);
        int a3 = specialPrize(chair3);
        int a4 = specialPrize(chair4);
        int arr[] = { a1, a2, a3, a4 };
        sort(arr, arr + 4);

        return arr[1];
    } else if (n==2){
        int a1 = chair[0][0];
        int a2 = chair[0][1];
        int a3 = chair[1][0];
        int a4 = chair[1][1];
        int arr[] = { a1, a2, a3, a4 };
        sort(arr, arr + 4);
        return arr[1];
    } else {
        return chair[0][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> chair(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> chair[i][j];
        }
    }

    int res = specialPrize(chair);

    cout << res;

    return 0;
}
