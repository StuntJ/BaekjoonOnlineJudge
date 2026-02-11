#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N,K;
    cin>>N>>K;

    vector<ll> v(N+1);
    for(int i=1;i<=N;i++) cin>>v[i];

    ll sum = accumulate(v.begin(),v.end(),0LL);
    deque<ll> dq;
    dq.push_back(0);
    vector<ll> dp(N+1);

    for(int i=1;i<=N;i++){
        while(!dq.empty() && dq.front()<i-K-1){
            dq.pop_front();
        }

        dp[i] = dp[dq.front()] + v[i];

        while(!dq.empty() && dp[dq.back()]>dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // for(auto i: dp) cout<<i<<' ';
    // cout<<'\n';
    ll ret = 1e15;
    for(int i=max(N-K,0);i<=N;i++){
        ret = min(ret,dp[i]);
    }
    cout<<sum-ret<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}