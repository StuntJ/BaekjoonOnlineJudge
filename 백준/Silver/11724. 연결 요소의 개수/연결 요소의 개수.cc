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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vvi adj(V + 1);
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<bool> visited(V + 1);

    function<void(int)> dfs = [&](int here)
        {
            visited[here] = true;
            for (auto next : adj[here])
                if(!visited[next])
                    dfs(next);
        };

    auto dfs_all = [&]()
        {
            int comp = 0;
            for (int i = 1; i <= V; i++)
            {
                if (!visited[i])
                {
                    comp++;
                    dfs(i);
                }
            }
            return comp;
        };

    cout << dfs_all() << '\n';
}