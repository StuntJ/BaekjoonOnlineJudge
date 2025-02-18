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

    int N, M, K;
    cin >> N >> M >> K;

    vi v(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    vvi adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vb visited(N + 1);
    auto dfs = [&](auto& dfs, int here)->pi
        {
            visited[here] = true;
            int ret = 1;
            int tot = v[here];

            for (auto next : adj[here])
            {
                if (!visited[next])
                {
                    pi r = dfs(dfs, next);
                    ret += r.first;
                    tot += r.second;
                }
            }
            return { ret,tot };
        };

    vpi data;
    data.push_back({ 0,0 });
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            data.push_back(dfs(dfs, i));
        }
    }

    int lim = data.size();
    //for (int i = 0; i < lim; i++)
    //    cout << data[i].first << ' ' << data[i].second << '\n';
    vi dp(K);
    for (int i = 1; i < lim; i++)
    {
        for (int j = K-1; j >= 0; j--)
        {
            if(j-data[i].first>=0) dp[j] = max(dp[j - data[i].first] + data[i].second, dp[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}