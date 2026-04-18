#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e12;

void solve() {
    int N,K;
    cin>>N>>K;

    vector<ll> v(N);
    for (auto &i : v) cin>>i;
    for (int i=0;i<N;i++) v.emplace_back(v[i]);

    ll ans = INF;
    for (int st = 0; st+K<=N ;st++) {
        int nd = st+N;
        vector<vector<ll>> dp(K+1,vector<ll>(2*N,-1));
        function<ll(int,int)> f = [&](int num,int idx) {
            if (idx==st+N) return 0LL;
            ll &ret = dp[num][idx];
            if (ret!=-1) return ret;
            ret = INF;

            ll plus = 0;
            if (num==K) {
                ll dist = 1;
                for (int i=idx+1;i<nd;i++) {
                    plus+=v[i]*dist;
                    dist++;
                }
                ret = plus;
            }
            else {
                ll dist = 0;
                for (int nxt = idx+1; nxt+K-num-1<=nd; nxt++) {
                    plus += v[nxt-1]*dist;
                    ret = min(ret,f(num+1,nxt)+plus);
                    dist++;
                }
            }
            return ret;
        };

        ans = min(ans,f(1,st));
    }

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}