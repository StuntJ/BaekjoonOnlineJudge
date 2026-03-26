#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;

const ll INF = 1e18;

struct pq_data{
    ll dist;
    ll here;
    ll leftK;

    bool operator < (const pq_data &rhs) const{
        return dist>rhs.dist;
    }
};

void solve(){
    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<pair<ll,ll>>> adj(N+1);

    for(int i=0;i<M;i++){
        ll a,b,t;
        cin>>a>>b>>t;
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }

    vector<vector<ll>> dist(N+1,vector<ll>(K+1,INF));
    priority_queue<pq_data> pq;
    dist[1][K] = 0;
    pq.push({0,1,K});

    while(!pq.empty()){
        ll here = pq.top().here;
        ll hereDist = pq.top().dist;
        ll hereleftK = pq.top().leftK;
        pq.pop();

        if(dist[here][hereleftK]<hereDist) continue;

        for(auto p : adj[here]){
            ll next = p.first;
            ll nextDist = hereDist + p.second;

            if(nextDist<dist[next][hereleftK]){
                dist[next][hereleftK] = nextDist;
                pq.push({nextDist,next,hereleftK});
            }
            if(hereleftK-1>=0){
                ll nextDist2 = hereDist;
                if(nextDist2<dist[next][hereleftK-1]){
                    dist[next][hereleftK-1] = nextDist2;
                    pq.push({nextDist2,next,hereleftK-1});
                }
            }
        }
    }
    
    ll ans = 1e18;
    for(int i=0;i<=K;i++){
        ans = min(ans,dist[N][i]);
    }

    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}