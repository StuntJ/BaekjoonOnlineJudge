#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin>>N;

    vector<ll> v(N);
    for (auto &i : v) cin>>i;

    vector<ll> dp(N,-1);
    dp[0] = 1;

    vector<pair<ll,ll>> top3;
    top3.push_back({dp[0],v[0]}); //dp[i],v[i]

    for (int i=1;i<N;i++) {
        for (int j=top3.size()-1;j>=0;j--) {
            if (v[i]!=top3[j].second+1 && v[i]!=top3[j].second-1) {
                dp[i] = top3[j].first+1;
                break;
            }
        }
        if (dp[i] == -1) dp[i] = 1;

        bool flag = false;
        for (int j=0;j<top3.size();j++) {
            if (v[i]==top3[j].second) {
                top3[j].first = dp[i];
                flag = true;
            }
        }
        if (!flag) top3.push_back({dp[i],v[i]});

        sort(top3.begin(),top3.end(),greater<pair<ll,ll>>());
        while (top3.size()>3) top3.pop_back();
        sort(top3.begin(),top3.end());
    }

    cout<<*max_element(dp.begin(),dp.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;//cin>>t;
    while (t--) {
        solve();
    }
}