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

    const int INF = 987654321;

    int N;
    cin >> N;
    vvi adj(N + 1);
    vvi dp(N + 1, vi(2,0));

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        
    }

    auto dfs = [&](auto& dfs, int here, int parent = -1)->void
    {
        int z = INF;
        if (adj[here].size() == 1 && adj[here][0] == parent)
        {
            dp[here][0] = 0;
            dp[here][1] = 1;
            return;
        }
        for (auto next : adj[here])
        {
            if (next == parent) continue;
            dfs(dfs, next, here);
            dp[here][0] += dp[next][1];
            dp[here][1] += min(dp[next][0], dp[next][1]);
        }
        dp[here][1]++;
        return;
    };

    dfs(dfs, 1);
    cout << min(dp[1][0], dp[1][1]);
}