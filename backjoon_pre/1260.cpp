#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited1[1001]; // 전역으로 선언 시 모두 false, 방문체크
bool visited2[1001];
vector<int> graph[1001]; // 벡터 자체가 1000개
queue<int> q; // bfs를 위한 큐

void dfs (int x) {
    visited1[x] = true;
    cout << x << " ";
    for (int i=0; i<graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited1[y]) dfs(y);
    }
}

void bfs (int s) {
    q.push(s);
    visited2[s] = true;
    while (!q.empty()){
        int x = q.front();
        cout << x << " ";
        q.pop();
    for (int i=0; i<graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited2[y]) {
            q.push(graph[x][i]);
            visited2[y] = true;
        } 
    }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M,V;
    cin >> N >> M >> V;

    for (int i=0; i<M; i++) {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1; i<=N; i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(V);
    cout << "\n";
    bfs(V);
}