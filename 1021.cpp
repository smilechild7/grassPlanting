#include <iostream>
#include <deque>

using namespace std;

void c1 (deque<int>& d1) {
    int a = d1.front();
    d1.pop_front();
    d1.push_back(a);
}

void c2 (deque<int>& d1) {
    int a = d1.back();
    d1.pop_back();
    d1.push_front(a);
}

int time1 (deque<int> d1, int n) {
    int t=0;
    while (true) {
        if (n==d1.front()){
            break;
        }
        c1(d1);
        t++;
    }
    return t;
}

int time2 (deque<int> d1, int n) {
    int t=0;
    while (true) {
        if (n==d1.front()){
            break;
        }
        c2(d1);
        t++;
    }
    return t;
}

int main() {
    int N,M;
    cin >> N >> M;

    deque<int> d1;
    deque<int> d2;
    for (int i=0; i<M; i++) {
        int n;
        cin >> n;
        d2.push_back(n);
    } 
    for (int i=0; i<N; i++) {
        d1.push_back(i+1);
    } 
    int sum=0;

    for (int i=0; i<M; i++) {
        int k = d2.front();
        int t1 = time1(d1,k);
        int t2 = time2(d1,k);
        if (t1 > t2) {
            sum+=t2;
            while (true) {
                if (k==d1.front()){
                    break;
                }
                c2(d1);
            }
            d1.pop_front();
        } else {
            sum+=t1;
            while (true) {
                if (k==d1.front()){
                    break;
                }
                c1(d1);
            }
            d1.pop_front();
        }
        d2.pop_front();
    }
    cout << sum;
}