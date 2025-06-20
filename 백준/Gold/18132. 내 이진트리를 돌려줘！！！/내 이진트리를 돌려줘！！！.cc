#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    typedef long long ll;
    const ll mod = 1e+9 + 7;
    vector<ll> dp(5001,-1);
    while(T--){
        int E;
        cin>>E;

        auto solve = [&](auto &solve, int x)->ll{
            if(x==0) return 1;
            ll &ret = dp[x];
            if(ret!=-1) return ret;
            ret = 0;

            ret += 2*solve(solve,x-1);
            ret%=mod;
            for(int i=0;i<=x-2;i++){
                ret += solve(solve,i)*solve(solve,x-2-i);
                ret%=mod;
            }
            return ret;
        };

        cout<<solve(solve,E)<<'\n';
    }
    // for(int i=0;i<5;i++) cout<<dp[i]<<' ';
}