#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;
    queue<int> q;
    int map[10000];
    bool visited[10000];
    vector <int> graph[10000];

    for(int i=0; i<N*M; i++){
        scanf("%1d", &map[i]);
	}

    for (int i=0; i<N; i++) {
        for (int j=0; j<M-1; j++) {
            if (map[j+M*i]==1 && map[j+M*i+1]==1) {
                graph[j+M*i].push_back(j+M*i+1);
                graph[j+M*i+1].push_back(j+M*i);
            }
        }
    }

    for (int i=0; i<N-1; i++) {
        for (int j=0; j<M; j++) {
            if (map[j+M*i]==1 && map[j+M*(i+1)]==1) {
                graph[j+M*i].push_back(j+M*(i+1));
                graph[j+M*(i+1)].push_back(j+M*i);
            }
        }
    }

    int t=0;
    q.push(0);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        int s = graph[k].size();

        for (int i=0; i<s; i++) {
            int y = graph[k][i];
            if (!visited[y]) {
                q.push(y);
                visited[y]=true;
                map[y] = map[k]+1;
            }
        }
    }
    cout << map[N*M-1];

    return 0;
}