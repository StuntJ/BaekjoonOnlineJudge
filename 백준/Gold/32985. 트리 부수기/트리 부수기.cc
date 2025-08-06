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

    int N;
    cin>>N;

    vvi adj(N);
    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vi depth(N,-1);

    auto dfs = [&](auto &dfs, int here, int d)->void{
        depth[here] = d;
        for(auto next : adj[here]){
            if(depth[next]==-1){
                dfs(dfs,next,d+1);
            }
        }
    };
    dfs(dfs,0,0);
    for(int i=N-1;i>0;i--){
        cout<<(N-1-depth[i])%2;
    }
}