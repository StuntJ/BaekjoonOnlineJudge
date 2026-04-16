#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int SZ = 1<<20;
ll T[SZ<<1];

void Set(int x, ll v) {
    x+=SZ; T[x] = v;
    while (x/=2) T[x] = T[x*2]+T[x*2+1];
}

ll Sum(int l, int r) {
    ll res = 0;
    for (l+=SZ,r+=SZ;l<=r;l/=2,r/=2) {
        if (l%2==1) res += T[l++];
        if (r%2==0) res += T[r--];
    }

    return res;
}

void solve() {
    int N;
    cin>>N;

    vector<ll> v(N);
    for (auto &i : v) cin>>i;
    vector<ll> vcomp;

    for (int i=0;i<N;i++) vcomp.push_back(v[i]);
    sort(vcomp.begin(),vcomp.end());
    vcomp.erase(unique(vcomp.begin(),vcomp.end()),vcomp.end());
    for (int i=0;i<N;i++) {
        v[i] = lower_bound(vcomp.begin(),vcomp.end(),v[i])-vcomp.begin();
    }

    vector<ll> lCnt(N),rCnt(N);
    for (int i=0;i<N;i++) {
        rCnt[i] = Sum(v[i]+1,N);
        Set(v[i],1);
    }

    fill(T,T+(SZ<<1),0LL);

    for (int i=N-1;i>=0;i--) {
        lCnt[i] = Sum(v[i]+1,N);
        Set(v[i],1);
    }

    int ans = 0;
    for (int i=0;i<N;i++) {
        ll mx = max(lCnt[i],rCnt[i]);
        ll mn = min(lCnt[i],rCnt[i]);

        if (mn*2<mx) ans++;
    }

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}