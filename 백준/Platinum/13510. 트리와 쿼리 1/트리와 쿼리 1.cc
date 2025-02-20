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

    int update(int idx, int newVal, int node, int nodeLeft, int nodeRight)
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
    vvpi adj(N + 1);
    vi s(N + 1), e(N + 1), c(N + 1);
    vi toPcost(N + 1);
    vi weight(N + 1), depth(N + 1), head(N + 1), in(N + 1), parent(N + 1);
    
    for (int i = 1; i < N; i++)
    {
        cin >> s[i] >> e[i] >> c[i];

        adj[s[i]].emplace_back(make_pair(e[i], c[i]));
        adj[e[i]].emplace_back(make_pair(s[i], c[i]));
    }

    auto dfs1 = [&](auto& dfs1, int here, int p = 0)->void
        {
            weight[here] = 1;
            for (auto& i : adj[here])
            {
                int next = i.first;
                int cost = i.second;

                if (next == p) continue;
                toPcost[next] = cost;
                depth[next] = depth[here] + 1;
                parent[next] = here;
                dfs1(dfs1, next, here);
                weight[here] += weight[next];
                if (weight[next] > weight[adj[here][0].first]) swap(i, adj[here][0]);
            }
        };

    int pv = 0;
    auto dfs2 = [&](auto& dfs2, int here, int p = 0)->void
        {
            in[here] = ++pv;
            for (auto& i : adj[here])
            {
                int next = i.first;
                if (next == p) continue;
                head[next] = (next == (adj[here][0].first) ? head[here] : next);
                dfs2(dfs2, next, here);
            }
        };

    dfs1(dfs1, 1);
    dfs2(dfs2, 1);

    vi v(N + 1);
    for (int i = 1; i <= N; i++)
        v[in[i]] = toPcost[i];

    RMQ seg(v);

    auto update = [&](int idx, int val)
        {
            if (depth[s[idx]] < depth[e[idx]]) swap(s[idx], e[idx]);
            seg.update(in[s[idx]], val);
        };

    auto query = [&](int u, int v) -> int
        {
            int ret = 0;
            while (head[u] != head[v])
            {
                if (depth[head[u]] < depth[head[v]]) swap(u,v);
                int st = head[u];
                ret = max(ret, seg.query(in[st], in[u]));
                u = parent[st];
            }
            if (depth[u] > depth[v]) swap(u, v);
            ret = max(ret, seg.query(in[u]+1, in[v]));
            return ret;
        };

    int Q;
    cin >> Q;
    while (Q--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int idx, val;
            cin >> idx >> val;
            update(idx, val);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }
}