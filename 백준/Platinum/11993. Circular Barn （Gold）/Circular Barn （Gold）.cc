#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin>>N;

    vector<int> v(N);
    for (auto &i : v) cin>>i;
    vector<bool> chk(N);

    int idx = 0;
    int st = 0;
    for (int i=0;i<N;i++) {
        if (i==0||!chk[i-1]) {
            st = i;
            idx = i;
        }

        bool flag = false;
        int oridx = idx;
        for (idx = oridx; idx<oridx+v[i];idx++) {
            if (!chk[idx%N]) chk[idx%N] = true;
            else flag = true;
            if (flag) break;
        }
        if (flag) break;
    }

    ll sum = 0;
    idx = st;
    int orp = st;
    for (int p = st; p<orp+N; p++) {
        int oridx = idx;
        for (idx = oridx ; idx<oridx+v[p%N];idx++)
            sum += (ll)(idx-p)*(idx-p);
    }

    cout<<sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}