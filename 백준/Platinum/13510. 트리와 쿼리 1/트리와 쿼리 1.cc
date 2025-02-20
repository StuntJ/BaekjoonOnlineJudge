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

struct RMQ
{
    int n;
    vi rangeMax;
    RMQ(const vi& array)
    {
        n = array.size();
        rangeMax.resize(n * 4);
        init(array, 1, 0, n - 1);
    }

    int init(const vi& array, int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight) return rangeMax[node] = array[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftMax = init(array, node * 2, nodeLeft, mid);
        int rightMax = init(array, node * 2 + 1, mid + 1, nodeRight);
        return rangeMax[node] = max(leftMax, rightMax);
    }

    const int INTMIN = numeric_limits<int>::min();
    int query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (nodeRight < left || right < nodeLeft) return INTMIN;
        if (left <= nodeLeft && nodeRight <= right) return rangeMax[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return max(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int query(int left, int right)
    {
        return query(left, right, 1, 0, n - 1);
    }

    int update(int idx, int newVal , int node, int nodeLeft, int nodeRight)
    {
        if (idx < nodeLeft || nodeRight < idx) return rangeMax[node];
        if (nodeLeft == nodeRight) return rangeMax[node] = newVal;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMax[node] = max(update(idx, newVal, node * 2, nodeLeft, mid), update(idx, newVal, node * 2 + 1, mid + 1, nodeRight));
    }

    int update(int idx, int newVal)
    {
        return update(idx, newVal, 1, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    const int lim = int(floor(log2(100000)));
    vvpi adj(N + 1);
    vvi dp(lim + 1, vi(N + 1));
    vi s(N + 1), e(N + 1), c(N + 1), toPcost(N + 1);
    vi parent(N + 1), depth(N + 1), weight(N + 1);
    vi where(N + 1), head(N + 1), ett(N + 1);

    for (int i = 1; i < N; i++)
    {
        cin >> s[i] >> e[i] >> c[i];

        adj[s[i]].emplace_back(make_pair(e[i],c[i]));
        adj[e[i]].emplace_back(make_pair(s[i],c[i]));
    }

    auto dfs = [&](auto& dfs, int here, int p = 0)->void
        {
            weight[here] = 1;
            for (auto& i : adj[here])
            {
                int next = i.first;
                if (next == p) continue;
                dp[0][next] = here;
                parent[next] = here;
                depth[next] = depth[here] + 1;
                toPcost[next] = i.second;
                dfs(dfs, next, here);
                weight[here] += weight[next];
            }
        };

    dfs(dfs,1, 0);

    for (int i = 1; i <= lim; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    int hldCounter, ettCounter;
    where[1] = head[1] = ett[1] = hldCounter = ettCounter = 1;
    auto hld = [&](auto& hld, int here, int p = 0)->void
        {
            sort(adj[here].begin(), adj[here].end(), [&](const pi& a, const pi& b)
                {
                    return weight[a.first] > weight[b.first];
                });

            int heavy = -1;
            for (auto& i : adj[here])
            {
                int next = i.first;
                if (next==p) continue;
                heavy = next;
                where[next] = where[here];
                ett[next] = ++ettCounter;
                hld(hld, next, here);
                break;
            }

            for (auto& i : adj[here])
            {
                int next = i.first;
                if (next == p || next == heavy) continue;
                where[next] = ++hldCounter;
                head[hldCounter] = next;
                ett[next] = ++ettCounter;
                hld(hld, next, here);
            }
        };

    hld(hld, 1,0);

    vi v(N + 1);
    for (int i = 1; i <= N; i++)
        v[ett[i]] = toPcost[i];
    
    auto lca = [&](int a, int b)
        {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int i = 0; diff; i++)
            {
                if (diff & 1) a = dp[i][a];
                diff >>= 1;
            }

            for (int i = lim; i >= 0; i--)
            {
                if (dp[i][a] != dp[i][b]) a = dp[i][a], b = dp[i][b];
            }

            if (a == b) return a;
            return dp[0][a];
        };

    RMQ seg(v);

    auto update = [&](int idx, int newVal)
        {
            if (depth[s[idx]] > depth[e[idx]]) swap(s[idx], e[idx]);
            seg.update(ett[e[idx]], newVal);
        };

    auto sub_query = [&](int s, int e)->int
        {
            int ret = 0;
            while (where[s] != where[e])
            {
                int hs = head[where[s]], he = head[where[e]];
                if (depth[hs] > depth[he])
                {
                    ret = max(ret, seg.query(ett[hs], ett[s]));
                    s = parent[hs];
                }
                else
                {
                    ret = max(ret, seg.query(ett[he], ett[e]));
                    e = parent[he];
                }
            }

            if (depth[s] < depth[e]) swap(s, e);
            ret = max(ret, seg.query(ett[e] + 1, ett[s]));
            return ret;
        };

    auto query = [&](int u, int v)
        {
            int t = lca(u, v);
            return max(sub_query(u, t), sub_query(v,t));
        };
    

    int Q;
    cin >> Q;

    while (Q--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int idx, newVal;
            cin >> idx >> newVal;
            update(idx, newVal);
        }
        else if (q == 2)
        {
            int u, v;
            cin >> u >> v;
            cout << query(u, v) << '\n';
        }
    }
}