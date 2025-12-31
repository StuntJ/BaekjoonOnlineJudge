#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll> dp(n+1);
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            for(int p=1;p<=n;p++){
                if(p-i>=0) dp[p] += dp[p-i];
            }
        }
    }
    cout<<dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}