#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        q.push(i + 1);
    }
    int n;
    q.pop();
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        q.push(n);
        q.pop();
    }
    cout << n;
    return 0;
}