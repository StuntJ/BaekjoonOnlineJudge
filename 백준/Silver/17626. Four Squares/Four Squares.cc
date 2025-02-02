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

ll dp[50001][5];
const ll INF = 1000000000;

ll dfs(ll x, ll depth =0)
{
    if (depth > 4) return INF;
    ll& ret = dp[x][depth];
    if (ret != 0) return ret;
    ret = INF;
    for (ll i = 1; i * i <= x; i++)
    {
        if (i * i == x) return ret = 1;
        ret = min(ret, dfs(x-i*i,depth+1));
    }
    ret++;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    cout << dfs(N);
}