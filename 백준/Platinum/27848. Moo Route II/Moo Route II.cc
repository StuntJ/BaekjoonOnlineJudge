#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;
const ll INF = 1e18;

struct adj_data{
    ll depTime;
    ll dest;
    ll arrvTime;

    bool operator < (const adj_data &rhs) const{
        return depTime < rhs.depTime;
    }
};

void solve(){
    int N,M;
    cin>>N>>M;

    vector<vector<adj_data>> adjInfo(N+1);
    
    for(int i=0;i<M;i++){
        ll c,r,d,s;
        cin>>c>>r>>d>>s;

        adjInfo[c].push_back({r,d,s});
    }

    vector<ll> A(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];

    for(int i=1;i<=N;i++) sort(all(adjInfo[i]));

    vector<ll> dist(N+1,INF);
    priority_queue<pair<ll,ll>> pq;
    dist[1] = 0;

    for(auto p : adjInfo[1]){
        ll next = p.dest;
        ll nextTime = p.arrvTime;

        if(dist[next]>nextTime){
            dist[next] = nextTime;
            pq.push({-nextTime,next});
        }
    }

    while(!pq.empty()){
        ll here = pq.top().second;
        ll hereTime = -pq.top().first;
        pq.pop();

        if(dist[here]<hereTime) continue;

        ll possible = hereTime + A[here];
        auto it = lower_bound(all(adjInfo[here]),possible,[&](adj_data &a, ll b){
            return a.depTime < b;
        });

        if(it==adjInfo[here].end()) continue;
        
        for(it; it!=adjInfo[here].end(); it++){
            ll next = it->dest;
            ll nextTime = it->arrvTime;

            if(dist[next]>nextTime){
                dist[next] = nextTime;
                pq.push({-nextTime,next});
            }
        }
    }

    for(int i=1;i<=N;i++) if(dist[i]==INF) dist[i] = -1;
    for(int i=1;i<=N;i++) cout<<dist[i]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}