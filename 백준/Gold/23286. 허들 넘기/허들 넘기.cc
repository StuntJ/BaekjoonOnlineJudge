#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,T;
    cin>>N>>M>>T;
    vector<unordered_map<int,int>> adj(N+1);
    while(M--){
        int u,v,h;
        cin>>u>>v>>h;

        if(adj[u].find(v)!=adj[u].end()){
            adj[u][v] = min(adj[u][v],h);
        }
        else adj[u][v] = h;
    }

    auto dijkstra = [&](int s){
        vector<int> dist(N+1,INF);
        priority_queue<pair<int,int>> pq;
        dist[s] = 0;
        pq.push({0,s});
        while(!pq.empty()){
            int here = pq.top().second;
            int hereDist = -pq.top().first;
            pq.pop();

            if(dist[here]<hereDist) continue;

            for(auto n : adj[here]){
                int next = n.first;
                int nextDist = max(hereDist,n.second);
                if(dist[next]>nextDist){
                    dist[next] = nextDist;
                    pq.push({-nextDist,next});
                }
            }
        }
        for(int i=0;i<=N;i++){
            if(dist[i]==INF) dist[i] = -1;
        }
        return dist;
    };

    vector<vector<int>> totDist(N+1);

    for(int i=1;i<=N;i++){
        totDist[i] = dijkstra(i);
    }

    while(T--){
        int a,b;
        cin>>a>>b;

        cout<<totDist[a][b]<<'\n';
    }

    /* for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<totDist[i][j]<<' ';
        }
        cout<<'\n';
    } */
}