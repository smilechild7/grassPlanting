#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[100][100] = {'O'};
bool visited[100][100];
char trash;
int main() {
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1c", &map[i][j]);
        }
        scanf("%1c", &trash);
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << map[i][j];
        }
    }
}