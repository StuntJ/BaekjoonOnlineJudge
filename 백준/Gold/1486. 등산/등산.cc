#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,T,D;
    cin>>N>>M>>T>>D;

    vector<vector<int>> grid(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;
            cin>>c;

            grid[i][j] = (c>='A'&&c<='Z' ? c-'A' : c-'a'+26);
        }
    }

    const int INF = 1e9;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    auto dijkstra = [&](int x, int y)->vector<vector<int>>{
        vector<vector<int>> dist(N,vector<int>(M,INF));
        priority_queue<array<int,3>> pq;
        pq.push({0,x,y});
        dist[x][y] = 0;

        while(!pq.empty()){
            auto [hereDist,x,y] = pq.top();
            hereDist = -hereDist;
            pq.pop();

            if(dist[x][y]<hereDist) continue;

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(0<=nx&&nx<N && 0<=ny&&ny<M && abs(grid[x][y]-grid[nx][ny])<=T){
                    int nextDist = hereDist + (grid[x][y]>=grid[nx][ny] ? 1 : (grid[nx][ny]-grid[x][y])*(grid[nx][ny]-grid[x][y]));
                    if(nextDist<dist[nx][ny])
                    {
                        dist[nx][ny] = nextDist;
                        pq.push({-nextDist,nx,ny});
                    }
                }
            }
        }
        return dist;
    };

    vector<vector<int>> dist = dijkstra(0,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==0&&j==0) continue;
            vector<vector<int>> m = dijkstra(i,j);
            dist[i][j]+=m[0][0];
        }
    }
    
    int ans = 0;
    int x,y;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(dist[i][j]<=D)
            {
                ans = max(ans, grid[i][j]);
                x = i; y = j;
            }

        }
    }
    /* for(auto i : grid){
        for(auto j : i)
            cout<<j<<' ';
        cout<<'\n';
    }
    cout<<'\n';

    for(auto i : dist){
        for(auto j : i)
            cout<<j<<' ';
        cout<<'\n';
    }
    cout<<'\n';
    cout<<x<<y<<'\n'; */
    cout<<ans;
}