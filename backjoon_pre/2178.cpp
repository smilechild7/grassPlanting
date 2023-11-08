#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;

bool visited[MAX][MAX];
char map[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M; cin >> N >> M;
    queue<pair<int,int>> q;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }

    q.push(make_pair(0,0));

    int res=0;

    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            visited[x][y] = true;
            q.pop();
            if (x==N-1 && y==M-1) {
                cout << res+1;
                return 0;
            }
            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && ny >=0 && int(map[nx][ny])=='1' && !visited[nx][ny] ) {
                        q.push(make_pair(nx,ny));
                        visited[nx][ny] = true;
                }
            }
        }
        res++;
    }
    cout << res;
    return 0;
}