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

const ll INF = 1e15;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    
    vll v(N+1);
    for(int i=1;i<=N;i++) cin>>v[i];
    vvll adj(N+1);
    for(int i=2;i<=N;i++){
        int x;
        cin>>x;

        adj[x].emplace_back(i);
        adj[i].emplace_back(x);
    }

    vvll dp(N+1,vll(2));
    auto dfs = [&](auto &dfs, int here, int parent)->void{
        for(auto next : adj[here]){
            if(next==parent) continue;
            dfs(dfs,next,here);
            dp[here][0] += max(dp[next][0],dp[next][1]);
            dp[here][1] += dp[next][0];
        }
        dp[here][1] += v[here];
    };

    dfs(dfs,1,-1);

    cout<<dp[1][1]<<' '<<dp[1][0]<<'\n';

    vll res;

    auto backtrack = [&](auto &backtrack, int here, int parent, int flag)->void{
        if(flag) res.emplace_back(here);
        for(auto next : adj[here]){
            if(next==parent) continue;
            if(flag) backtrack(backtrack,next,here,0);
            else{
                if(dp[next][0]>dp[next][1]) backtrack(backtrack,next,here,0);
                else backtrack(backtrack,next,here,1);
            }
        }
    };
    backtrack(backtrack,1,-1,1);
    sort(res.begin(),res.end());
    res.emplace_back(-1);
    for(auto i : res) cout<<i<<' ';
    cout<<'\n';
    res.clear();
    backtrack(backtrack,1,-1,0);
    sort(res.begin(),res.end());
    res.emplace_back(-1);
    for(auto i : res) cout<<i<<' ';
    cout<<'\n';
}