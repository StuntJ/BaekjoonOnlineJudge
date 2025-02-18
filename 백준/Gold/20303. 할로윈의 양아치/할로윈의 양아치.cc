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

struct disjoint_set
{
    vector<int> parent, count, total;
    disjoint_set(int n) : parent(n), count(n, 1), total(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) //정점이 어느 집합에 속하는지 알려주는 함수이다.
    {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) //u와 v를 같은 집합에 속하게 하는 함수이다.
    {
        u = find(u); v = find(v);
        if (u == v) return false;
        parent[u] = v;
        count[v] += count[u];
        total[v] += total[u];
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    disjoint_set ds(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> ds.total[i];

    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        ds.merge(a, b);
    }

    vpi data;
    data.push_back({ 0,0 });
    for (int i = 1; i <= N; i++)
    {
        if (ds.find(i) == i) data.emplace_back(make_pair(ds.count[i], ds.total[i]));
    }

    int lim = data.size();
    //for (int i = 0; i < lim; i++)
    //    cout << data[i].first << ' ' << data[i].second << '\n';
    vi dp(K);
    for (int i = 1; i < lim; i++)
    {
        for (int j = K - 1; j >= 0; j--)
        {
            if (j - data[i].first >= 0) dp[j] = max(dp[j - data[i].first] + data[i].second, dp[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}