#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N;
    ll D;
    cin>>N>>D;

    vector<bool> chk1(N),chk2(N);
    vector<pair<ll,ll>> v(N);
    for (auto &i : v) cin>>i.first>>i.second;

    sort(v.begin(),v.end());

    auto f = [&](bool rev) {
        queue<pair<ll,ll>> q;
        multiset<ll> mp;
        for (int i=0;i<N;i++) {
            while (!q.empty() && abs(v[i].first-q.front().first)>D) {
                auto it = mp.find(q.front().second);
                mp.erase(it);
                q.pop();
            }

            if (!mp.empty() && *mp.rbegin()>=2*v[i].second) {
                if (rev) chk2[N-i-1] = true;
                else chk1[i] = true;
            }

            q.push(v[i]);
            mp.insert(v[i].second);
        }
    };

    f(false);
    reverse(v.begin(),v.end());
    f(true);

    int cnt = 0;
    for (int i=0;i<N;i++) if (chk1[i]&&chk2[i]) cnt++;
    cout<<cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}