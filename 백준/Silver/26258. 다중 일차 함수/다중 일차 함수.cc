#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<double,double>> v(N);

    for (auto& i : v) cin >> i.first >> i.second;

    int Q;
    cin >> Q;
    while (Q--)
    {
        double k;
        cin >> k;

        int idx = lower_bound(v.begin(), v.end(), make_pair(k,0.0)) - v.begin();
        if (fabs(v[idx].second - v[idx-1].second) < DBL_EPSILON) cout << 0 << '\n';
        else if (v[idx].second - v[idx-1].second > 0) cout << 1 << '\n';
        else cout << -1 << '\n';
    }
}