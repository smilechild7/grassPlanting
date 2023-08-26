#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited1[10000];
bool visited2[10000];

int main() {
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int M = N*N;
    queue<int> q1;
    queue<int> q2;
    char RGB[10000]={'O'};
    char GGB[10000]={'O'};
    char trash[100];
    vector <int> graph1[10000];
    vector <int> graph2[10000];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1c", &RGB[j+N*i]);
            if (RGB[j+N*i]=='R') {
                GGB[j+N*i]='G';
            } else {
                GGB[j+N*i]=RGB[j+N*i];
            }
        }
        scanf("%c",&trash[i]);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N-1; j++) {
            if (RGB[j+N*i]==RGB[j+N*i+1]) {
                graph1[j+N*i].push_back(j+N*i+1);
                graph1[j+N*i+1].push_back(j+N*i);
            }
            if (GGB[j+N*i]==GGB[j+N*i+1]) {
                graph2[j+N*i].push_back(j+N*i+1);
                graph2[j+N*i+1].push_back(j+N*i);
            }
        }
    }

    for (int i=0; i<N-1; i++) {
        for (int j=0; j<N; j++) {
            if (RGB[j+N*i]==RGB[j+N*(i+1)]) {
                graph1[j+N*i].push_back(j+N*(i+1));
                graph1[j+N*(i+1)].push_back(j+N*i);
            }
            if (GGB[j+N*i]==GGB[j+N*(i+1)]) {
                graph2[j+N*i].push_back(j+N*(i+1));
                graph2[j+N*(i+1)].push_back(j+N*i);
            }
        }
    }
    int cnt1=0;
    int cnt2=0;
    for (int i=0; i<N*N; i++) {
        if (!visited1[i]) {
            q1.push(i);
            visited1[i]=true;
            while (!q1.empty()){
                int x1 = q1.front();
                for (int j=0; j<graph1[x1].size(); j++) {
                    int y1 = graph1[x1][j];
                    if (!visited1[y1]) {
                        q1.push(y1);
                        visited1[y1]=true;
                    }
                    q1.pop();
                }
            }
            cnt1+=1;
        }
    }
    for (int i=0; i<N*N; i++) {
        if (!visited2[i]) {
            q2.push(i);
            visited2[i]=true;
            while (!q2.empty()){
                int x2 = q2.front();
                for (int j=0; j<graph2[x2].size(); j++) {
                    int y2 = graph2[x2][j];
                    if (!visited2[y2]) {
                        q2.push(y2);
                        visited2[y2]=true;
                    }
                q2.pop();
                }
            }
            cnt2+=1;
        }
    }
    cout << cnt1 <<" "<<cnt2;
}
