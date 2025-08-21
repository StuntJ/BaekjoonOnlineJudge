#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N,M;
    cin>>N>>M;

    vector<pair<ll,ll>> menu(M);
    for(auto &i : menu) cin>>i.first>>i.second;
    sort(menu.begin(),menu.end());

    const ll INF = 1e15;
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,INF));
    dp[0][0] = 0;

    ll ans = 1e18;
    for(int j=0;j<M;j++){
        for(int i=N;i>=0;i--){ //idx
            for(int k=0;k<=j;k++){
                if(dp[i][k]==INF) continue;
                int n = min(N,i+menu[j].second);
                dp[n][k+1] = min(dp[n][k+1],dp[i][k]+(n-i)*menu[j].first);
                //if(n==N) ans = min(ans,dp[n][k+1]*(k+1));
            }
        }
    }
    /* for(auto i : dp){
        for(auto j : i) cout<<j<<' ';
        cout<<'\n';
    }  */
    for(int i=1;i<=M;i++) ans = min(ans,dp[N][i]*i);
    cout<<ans;

}