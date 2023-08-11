#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int dx[4]= {1,0,-1,0};
    int dy[4]= {0,1,0,-1};
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n,m,k;
        int cnt = 0;
        cin >> n >> m >> k;
        int arr[50][50]= {0};
        for(int j=0; j<k; j++){
            int a,b;
            cin >> a >> b;
            arr[a][b]=1;
        }
        bool visit[50][50] = {0};
        queue<pair<int,int>> q;
        for(int u=0; u<n; u++){
            for(int h=0; h<m; h++){
                if(visit[u][h]!=1 && arr[u][h]==1){
                    visit[u][h]=1;
                    q.push({u,h});
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        for(int j=0; j<4; j++){
                            int x = p.first + dx[j];
                            int y = p.second + dy[j];
                            if(x<0 || x>=n || y<0 || y>=m){
                                continue;
                            }
                            if(visit[x][y]==1 || arr[x][y]!=1){
                                continue;
                            }
                            visit[x][y]=1;
                            q.push({x,y});
                        }
                    }
                    cnt ++;
                }
            }
        }
        cout << cnt<<"\n";
    }
}