#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;
    int size = N*M;
    int map[10000];
    queue<int> q;
    bool visited[10000];
    vector <int> graph[10000];

    for (int i=0; i<size; i++) {
        char c; cin >> c;
        map[i]=int(c);
    }

    



    return 0;
}