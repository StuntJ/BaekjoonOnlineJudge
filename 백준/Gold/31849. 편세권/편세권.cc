#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,R,C;
    cin>>N>>M>>R>>C;

    struct pq_data{
        int D;
        int x;
        int y;
        int p;
        bool operator < (const pq_data &rhs) const{
            return D>rhs.D;
        }
    };

    priority_queue<pq_data> pq;
    const int INF = 1e9;
    vector<vector<int>> dist(N,vector<int>(M,INF));
    for(int i=0;i<R;i++){
        int a,b,p;
        cin>>a>>b>>p;
        a--;
        b--;
        pq.push({0,a,b,p});
    }
    
    queue<pair<int,int>> q;
    for(int i=0;i<C;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        q.push({a,b});
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    while(!pq.empty()){
        int hereDist = pq.top().D;
        int x = pq.top().x;
        int y = pq.top().y;
        int p = pq.top().p;
        pq.pop();

        if(dist[x][y]<hereDist) continue;

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx&&nx<N && 0<=ny&&ny<M){
                int nextDist = hereDist+p;
                if(dist[nx][ny]>nextDist){
                    pq.push({nextDist,nx,ny,p});
                    dist[nx][ny] = nextDist;
                }
            }
        }
    }

    int ans = INF;
    while(!q.empty()){
        ans = min(ans,dist[q.front().first][q.front().second]);
        q.pop();
    }
    cout<<ans;
}