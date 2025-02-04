#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vd x(N);
    vd y(N);

    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    int Q;
    cin >> Q;
    while (Q--)
    {
        double k;
        cin >> k;

        int idx = lower_bound(x.begin(), x.end(), k) - x.begin();
        if (fabs(y[idx] - y[idx-1]) < DBL_EPSILON) cout << 0 << '\n';
        else if (y[idx] - y[idx-1] > 0) cout << 1 << '\n';
        else cout << -1 << '\n';
    }
}