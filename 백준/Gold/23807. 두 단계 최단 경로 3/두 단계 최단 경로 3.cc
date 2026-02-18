#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e15;

void solve(){
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,ll>>> adj(N+1);
    for(int i=0;i<M;i++){
        int u,v;
        ll w;

        cin>>u>>v>>w;

        adj[u].emplace_back(make_pair(v,w));
        adj[v].emplace_back(make_pair(u,w));
    }

    int X,Z;
    cin>>X>>Z;

    int P;
    cin>>P;
        
    vector<int> via(P);
    for(auto &i : via) cin>>i;

    auto dijkstra = [&](int start)->vector<ll>{
        vector<ll> dist(N+1,INF);
        priority_queue<pair<ll,int>> pq;
        dist[start] = 0;
        pq.push({0,start});

        while(!pq.empty()){
            int here = pq.top().second;
            ll hereDist = -pq.top().first;
            pq.pop();

            if(hereDist>dist[here]) continue;

            for(auto i : adj[here]){
                ll nextDist = hereDist + i.second;
                int next = i.first;

                if(nextDist<dist[next]){
                    dist[next] = nextDist;
                    pq.push({-nextDist,next});
                }
            }
        }

        return dist;
    };

    vector<vector<ll>> viaDist(P);
    for(int i=0;i<P;i++){
        viaDist[i] = dijkstra(via[i]);
    }
    vector<ll> xDist = dijkstra(X);

    ll ans = INF;
    for(int i=0;i<P;i++){
        for(int j=0;j<P;j++){
            for(int k=0;k<P;k++){
                if(i==j || j==k || k==i) continue;
                int firstV = via[i];
                int secondV = via[j];
                int thirdV = via[k];

                ll totalDist = xDist[firstV] + viaDist[i][secondV] + viaDist[j][thirdV] + viaDist[k][Z];
                ans = min(totalDist,ans);
            }
        }
    }
    cout<< (ans>=INF ? -1 : ans);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}