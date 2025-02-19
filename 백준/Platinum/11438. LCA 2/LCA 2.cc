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

const int lim = (int)floor(log2(100000));
vector<vector<int>> dp;
vector<vector<int>> tree;
vector<int> depth;
vector<bool> visited;

void dfs(int here, int d)
{
    visited[here] = true;
    depth[here] = d;
    for (auto next : tree[here])
    {
        if (!visited[next])
        {
            dp[0][next] = here;
            dfs(next, d + 1);
        }
    }
}

void makeTable(int N)
{
    for (int i = 1; i <= lim; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
}

int lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff>0 ; i++) //1. 두 노드의 깊이를 같게 만든다. 
    {
        if (diff & 1) u = dp[i][u];
        diff >>= 1;
    }
    if (u == v) return u; //예외) v가 u의 조상이면 당장 return u;

    for (int i = lim; i >= 0; i--)
    {
        if (dp[i][u] != dp[i][v]) u = dp[i][u], v = dp[i][v];
    }
    return dp[0][u];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    dp = vector<vector<int>>(lim+1, vector<int>(N + 1));
    visited = vector<bool>(N + 1);
    depth = vector<int>(N + 1);
    tree = vector<vector<int>>(N+1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    dfs(1, 0);
    makeTable(N);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int a, b;
        cin >> a >> b;


        cout << lca(a, b) << '\n';
    }
}