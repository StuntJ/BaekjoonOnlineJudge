#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,T;
    cin>>N>>M>>T;

    vector<vector<int>> grid(N,vector<int>(M));
    for(auto &i : grid) for(auto &j : i) cin>>j;

    const int INF = 1e9;
    vector<vector<vector<int>>> dist(2,vector<vector<int>>(N,vector<int>(M,INF)));
    struct q_data{
        int ab;
        int x;
        int y;
    };
    queue<q_data> q;
    dist[0][0][0] = 0;
    q.push({0,0,0});

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    while(!q.empty()){
        int hab = q.front().ab;
        int hx = q.front().x;
        int hy = q.front().y;
        //cout<<hab<<' '<<hx<<' '<<hy<<'\n';
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = hx+dx[i];
            int ny = hy+dy[i];
            if(0<=nx&&nx<N && 0<=ny&&ny<M){
                if(hab==0 && grid[nx][ny]==1) continue;
                if(grid[nx][ny]==2){
                    if(dist[1][nx][ny]==INF){
                        dist[1][nx][ny] = dist[hab][hx][hy]+1;
                        q.push({1,nx,ny});
                    }
                }
                else{
                    if(dist[hab][nx][ny]==INF){
                        dist[hab][nx][ny] = dist[hab][hx][hy]+1;
                        q.push({hab,nx,ny});
                    }
                }
            }
        }
    }
    int ans = min(dist[0][N-1][M-1],dist[1][N-1][M-1]);
    if(ans>T) cout<<"Fail";
    else cout<<ans;
}