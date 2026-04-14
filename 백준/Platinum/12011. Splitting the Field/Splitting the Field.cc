#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    int N;
    cin>>N;

    vector<pair<ll,ll>> v(N);
    for (auto &i : v) cin>>i.first>>i.second;

    vector<ll> fromLeft(N),fromRight(N),fromUp(N),fromDown(N);

    ll mnArea = INF;
    ll mxRange = 0;
    ll mnRange = INF;
    sort(v.begin(),v.end());

    for (int i=0;i<N;i++) {
        ll pivot = v[i].first;
        int idx = i;
        while (idx<N && v[idx].first==pivot) {
            mxRange = max(mxRange,v[idx].second);
            mnRange = min(mnRange,v[idx].second);
            idx++;
        }

        i = idx-1;
        ll width = v[i].first-v[0].first;
        fromLeft[i] = width*(mxRange-mnRange);
    }
    ll orArea = *max_element(fromLeft.begin(),fromLeft.end());

    mxRange = 0;
    mnRange = INF;
    for (int i=N-1;i>=0;i--) {
        ll pivot = v[i].first;
        int idx = i;
        while (idx>=0 && v[idx].first==pivot) {
            mxRange = max(mxRange,v[idx].second);
            mnRange = min(mnRange,v[idx].second);
            idx--;
        }
        ll opArea = -1;
        if (idx>=0) {
            opArea = fromLeft[idx];
        }
        i = idx+1;
        ll width = v[N-1].first-v[i].first;
        fromRight[i] = width*(mxRange-mnRange);
        if (opArea!=-1)
            mnArea = min(opArea+fromRight[i],mnArea);
    }

    sort(v.begin(),v.end(),[&](pair<ll,ll> &a, pair<ll,ll>&b) {
        if (a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    });

    mxRange = 0;
    mnRange = INF;
    for (int i=0;i<N;i++) {
        ll pivot = v[i].second;
        int idx = i;
        while (idx<N && v[idx].second==pivot) {
            mxRange = max(mxRange,v[idx].first);
            mnRange = min(mnRange,v[idx].first);
            idx++;
        }

        i = idx-1;
        ll width = v[i].second-v[0].second;
        fromDown[i] = width*(mxRange-mnRange);
    }

    mxRange = 0;
    mnRange = INF;

    for (int i=N-1;i>=0;i--) {
        ll pivot = v[i].second;
        int idx = i;
        while (idx>=0 && v[idx].second==pivot) {
            mxRange = max(mxRange,v[idx].first);
            mnRange = min(mnRange,v[idx].first);
            idx--;
        }

        ll opArea = -1;
        if (idx>=0) {
            opArea = fromDown[idx];
        }
        i = idx+1;
        ll width = v[N-1].second-v[i].second;
        fromUp[i] = width*(mxRange-mnRange);
        if (opArea!=-1)
            mnArea = min(mnArea,opArea+fromUp[i]);
    }

    cout<<orArea-mnArea;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}