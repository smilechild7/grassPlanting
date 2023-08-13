#include <iostream>
#include <vector>

using namespace std;

bool visited[1000]; // 전역으로 선언 시 모두 false, 방문체크
vector<int> graph[1000]; // 벡터 자체가 1000개

void dfs (int x) {
    visited[x] = true;
    
    for (int i=0; i<graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) dfs(y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M,V;
    cin >> N >> M >> V;


}