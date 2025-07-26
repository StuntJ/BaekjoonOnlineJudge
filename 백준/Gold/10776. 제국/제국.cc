#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K,N,M;
    cin>>K>>N>>M;

    struct node{
        int here;
        int t;
        int h;

        bool operator < (const node &rhs) const{
            return t>rhs.t;
        }
    };

    vector<vector<node>> adj(N+1);
    while(M--){
        int x,y,t,h;
        cin>>x>>y>>t>>h;
        
        adj[x].push_back({y,t,h});
        adj[y].push_back({x,t,h});
    }

    int st,nd;
    cin>>st>>nd;
    priority_queue<node> pq;
    pq.push({st,0,0});
    const int INF = numeric_limits<int>::max();
    vector<vector<int>> dist(N+1,vector<int>(K,INF));
    dist[st][0] = 0;

    while(!pq.empty()){
        int here = pq.top().here;
        int hereH = pq.top().h;
        int hereDist = pq.top().t;
        pq.pop();

        if(hereDist>dist[here][hereH]) continue;

        for(auto p : adj[here]){
            int next = p.here;
            int nextH = hereH + p.h;
            int nextDist = hereDist + p.t;
            if(nextH>=K) continue;

            if(nextDist<dist[next][nextH]){
                pq.push({next,nextDist,nextH});
                dist[next][nextH] =  nextDist;
            }
        }
    }

    int ans = INF;
    for(int i=0;i<K;i++) ans = min(ans, dist[nd][i]);
    cout<<(ans==INF ? -1 : ans);
}