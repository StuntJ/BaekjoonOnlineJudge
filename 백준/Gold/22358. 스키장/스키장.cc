#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N,M,K,S,T;
    cin>>N>>M>>K>>S>>T;

    vector<vector<pair<ll,ll>>> adj(N+1);
    while(M--){
        ll a,b,t;
        cin>>a>>b>>t;
        adj[a].push_back({b,t});
        adj[b].push_back({a,0});
    }

    vector<vector<ll>> dp(N+1,vector<ll>(K+1,-1));
    const ll INF = 1e18;
    auto dfs = [&](auto &dfs, ll here, ll k)->ll{
        ll &ret = dp[here][k];
        if(ret!=-1) return ret;
        ret = -INF;
        
        bool flag = false;
        for(auto p : adj[here]){
            ll next = p.first;
            ll nextDist = p.second;
            if(nextDist==0 && k>0){ ret = max(ret,dfs(dfs,next,k-1)); flag = true;}
            else if(nextDist!=0) {ret = max(ret,dfs(dfs,next,k)+nextDist); flag = true;}
        }
        if(!flag&&here!=T) return ret = -INF;
        if(here==T) return ret = max(0LL,ret);
        return ret;
    };

    ll ans = dfs(dfs,S,K);
    cout<<(ans>=0 ? ans : -1);
}