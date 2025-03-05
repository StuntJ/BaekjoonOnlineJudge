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

struct RSQ
{
    int n;
    vector<int> rangeSum;
    RSQ(const vector<int>& array)
    {
        n = array.size();
        rangeSum.resize(n * 4); //대충 n*4정도 할당하면 맞음
        init(array, 1, 0, n - 1); //rangeMin 배열 초기화
    }

    int init(const vector<int>& array, int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight) return rangeSum[node] = array[nodeLeft]; //nodeLeft==nodeRight면 array값을 rangeMin[node]에 그대로 넣는다.
        int mid = (nodeLeft + nodeRight) / 2;
        int leftSum = init(array, node * 2, nodeLeft, mid); //구간 반으로 쪼개고 그 반에서 최솟값을 구한다.
        int rightSum = init(array, node * 2 + 1, mid + 1, nodeRight); //구간 반으로 쪼개고 그 반에서 최솟값을 구한다.
        return rangeSum[node] = leftSum + rightSum; //양 구간에서 나온 최솟값을 rangeMin[node]에 저장한다.
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (nodeRight < left || right < nodeLeft) return 0; //구간을 벗어났을 경우 return 값을 무시하기 위해 항등원 INTMAX를 return 한다.
        if (left <= nodeLeft && nodeRight <= right) return rangeSum[node]; //구간안에 완전히 들어온 경우 값을 리턴한다.
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight); //두개의 쪼개진 구간에서 작은 값을 리턴한다.
    }

    int query(int left, int right) //주의 함수의 return 자료형을 typedef로 선언하면 오버로딩이 불가능
    {
        return query(left, right, 1, 0, n - 1);
    }

    int update(int index, int newValue, int node, int nodeLeft, int nodeRight)
    {
        if (index < nodeLeft || nodeRight < index) return rangeSum[node]; //변경되는 index값을 벗어난 구간이면 그냥 있는 값을 리턴한다.
        if (nodeLeft == nodeRight) return rangeSum[node] = newValue; //index에 도달했으면 rangeMin[node] 에 newValue를 넣는다.
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeSum[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight); //두 개의 쪼개진 구간에서 최솟값을 받아 현재 노드에 넣는다.
    }

    int update(int index, int newValue) //주의 함수의 return 자료형을 typedef로 선언하면 오버로딩이 불가능
    {
        return update(index, newValue, 1, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    Q += N - 1;

    vvi adj(N + 1);
    vi depth(N + 1), in(N + 1), parent(N + 1), weight(N + 1), head(N + 1);

    for (int i = 2; i <= N; i++)
    {
        int a;
        cin >> a;

        adj[i].emplace_back(a);
        adj[a].emplace_back(i);
    }

    auto dfs1 = [&](auto& dfs1, int here, int p = -1)->void
        {
            weight[here] = 1;
            for (auto& next : adj[here])
            {
                if (next == p) continue;
                depth[next] = depth[here] + 1;
                parent[next] = here;
                dfs1(dfs1, next, here);
                weight[here] += weight[next];
                if (weight[next] > weight[adj[here][0]]) swap(next, adj[here][0]);
            }
        };

    int pv = 0;

    head[1] = 1;
    auto dfs2 = [&](auto& dfs2, int here, int p = -1)->void
        {
            in[here] = ++pv;
            for (auto next : adj[here])
            {
                if (next == p) continue;
                head[next] = (next == adj[here][0] ? head[here] : next);
                dfs2(dfs2, next, here);
            }
        };

    dfs1(dfs1, 1);
    dfs2(dfs2, 1);

    vi v(N + 1, 1);
    RSQ seg(v);

    auto update = [&](int idx)->void
        {
            seg.update(in[idx], 0);
        };

    auto query = [&](int u, int v)->bool
        {
            while (head[u] != head[v])
            {
                if (depth[head[u]] < depth[head[v]]) swap(u, v);
                int k = seg.query(in[head[u]], in[u]);
                if (k != in[u] - in[head[u]] + 1) return false;
                u = parent[head[u]];
            }

            if (depth[u] > depth[v]) swap(u, v);
            if (u != v)
            {
                int k = seg.query(in[u] + 1, in[v]);
                if (k != in[v] - (in[u] + 1) + 1) return false;
            }

            return true;
        };

    while (Q--)
    {
        int q;
        cin >> q;
        if (q == 0)
        {
            int b;
            cin >> b;
            update(b);
        }
        else
        {
            int c, d;
            cin >> c >> d;
            cout << (query(c, d) ? "YES" : "NO") << '\n';
        }
    }

}