#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[1000001];
bool isRot[1000001];
int tomato[1000001] = {-2};

vector<int> graph[1000001];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M,N; 
    cin >> N >> M;
    
    for(int i=1; i<=N*M; i++) {
        int k; cin >> k;
        tomato[i] = k;
        if (k==1) {
            q.push(i);
            visited[i]=true;
        } else if (k==-1) {
            isRot[i]=true;
        }
    }

    for (int i=0; i<M; i++) {
        for (int j=1; j<N; j++) {
            if (!isRot[j+N*i] && !isRot[j+N*i+1]) {
                graph[j+N*i].push_back(j+N*i+1);
                graph[j+N*i+1].push_back(j+N*i);  
            }
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=0; j<M-1; j++) {
            if (!isRot[i+N*j] && !isRot[i+N*(j+1)]) {
                graph[i+N*j].push_back(i+N*(j+1));
                graph[i+N*(j+1)].push_back(i+N*j);
            }
        }
    }
    
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i=0; i<graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
                tomato[y] = tomato[x]+1;
            }
        }
    }
    int max=1;
    for (int i=1; i<=N*M; i++) {
        if (tomato[i]==0) {
            cout << -1;
            return 0;
        } else {
            if (tomato[i]>max) {
                max = tomato[i];
            }
        }
    }
    cout << max-1;
    return 0;
}
