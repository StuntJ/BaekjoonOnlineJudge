#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod = 1e9 +9;

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<ll> dp(N+1);
        dp[0] = 1;
        for(int i=1;i<=N;i++){
            dp[i] += dp[i-1];
            if(i>1) dp[i] += dp[i-2];
            if(i>2) dp[i] += dp[i-3];
            dp[i]%=mod;
        }
        cout<<dp[N]<<'\n';
    }
}