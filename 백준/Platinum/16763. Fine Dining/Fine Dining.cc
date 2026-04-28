#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

struct pq_data {
    int ver;
    ll dist;
    bool ate;

    bool operator < (const pq_data &rhs) const {
        return dist > rhs.dist;
    }
};

void solve() {
    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<pair<int,ll>>> adj(N+1);
    for (int i=0;i<M;i++) {
        int a,b;
        ll  w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    vector<ll> hay(N+1);

    for (int i=0;i<K;i++) {
        int a;
        ll b;
        cin>>a>>b;

        if (hay[a]<b) hay[a] = b;
    }

    auto dijkstra = [&](int st, bool ate) -> vector<vector<ll>> {
        priority_queue<pq_data> pq;
        vector<vector<ll>> dist(2,vector<ll>(N+1,INF));
        if (!ate&&hay[N]!=0) {
            dist[!ate][N] = -hay[N];
            pq.push({st,0,!ate});
        }
        dist[ate][st] = 0;
        pq.push({st,0,ate});

        while (!pq.empty()) {
            pq_data hData = pq.top();
            pq.pop();
            int here = hData.ver;
            ll hereDist = hData.dist;
            bool hate = hData.ate;

            if (dist[hate][here]<hereDist) continue;

            for (auto p : adj[here]) {
                int next = p.first;
                ll nextDist = hereDist + p.second;

                if (hate) {
                    if (dist[hate][next]>nextDist) {
                        dist[hate][next] = nextDist;
                        pq.push({next,nextDist,hate});
                    }
                }
                else {
                    if (dist[hate][next]>nextDist) {
                        dist[hate][next] = nextDist;
                        pq.push({next,nextDist,hate});
                    }
                    if (hay[next]!=0) {
                        if (dist[!hate][next]>nextDist-hay[next]) {
                            dist[!hate][next] = nextDist-hay[next];
                            pq.push({next,nextDist-hay[next],!hate});
                        }
                    }
                }
            }
        }

        return dist;
    };

    vector<vector<ll>> fDist = dijkstra(N,true);
    vector<vector<ll>> lDist = dijkstra(N,false);

    for (int i=1;i<N;i++) {
        //cout<<lDist[1][i] << ' ' << fDist[1][i]<<'\n';
        if (lDist[1][i]>fDist[1][i]) {
            cout<<0<<'\n';
        }
        else cout<<1<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}