#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int LIM = 500010;

constexpr int SZ = 1<<20;
ll T[SZ<<1];

void Set(int x, ll v) {
    x+=SZ; T[x] = v;
    while (x/=2) T[x] = max(T[x*2],T[x*2+1]);
}

ll getMax(int l, int r) {
    ll res = 0;
    for (l+=SZ,r+=SZ; l<=r; l/=2,r/=2) {
        if (l%2==1) res = max(res,T[l++]);
        if (r%2==0) res = max(res,T[r--]);
    }
    return res;
}

void solve() {
    int N,K,D;
    cin>>N>>K>>D;

    vector<ll> recordMx(K);
    vector<ll> v(N);
    for (auto &i : v) cin>>i;

    Set(v[0],1);
    recordMx[v[0]%K] = 1;
    vector<ll> dp(N);
    dp[0] = 1;

    for (int i=1;i<N;i++) {
        dp[i] = max(recordMx[v[i]%K]+1,1LL);
        dp[i] = max(dp[i],getMax(max(0LL,v[i]-D),min((ll)LIM,v[i]+D))+1);

        recordMx[v[i]%K] = max(recordMx[v[i]%K],dp[i]);
        Set(v[i],dp[i]); //v[i]가 똑같을때는 단조성이 성립
    }
    // for (auto &i : dp) cout<<i<< ' ';
    // cout<<'\n';
    cout<<*max_element(dp.begin(),dp.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}