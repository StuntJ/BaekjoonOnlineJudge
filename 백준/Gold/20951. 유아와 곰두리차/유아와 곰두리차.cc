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

    int N,M;
    cin>>N>>M;

    vvi adj(N+1);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    const ll mod = 1e9+7;
    vvll dp(8,vll(N+1));
    for(int i=1;i<=N;i++) dp[0][i] = 1;

    for(int i=1;i<8;i++){
        for(int j=1;j<=N;j++){
            for(auto con : adj[j])
                dp[i][j] = (dp[i][j] + dp[i-1][con])%mod;
        }
    }

    ll sum = 0;
    /* for(int i=0;i<8;i++){
        for(int j=1;j<=N;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n'; */
    for(int i=1;i<=N;i++) sum = (dp[7][i] + sum)%mod;
    cout<<sum;
}