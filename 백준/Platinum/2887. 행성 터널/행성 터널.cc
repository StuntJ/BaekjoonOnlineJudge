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

struct v_data
{
    int idx;
    int x;
    int y;
    int z;
};

struct disjoint_set
{
    vector<int> parent;
    disjoint_set(int n) : parent(n)
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
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<v_data> v(N);

    int idx = 0;
    for (auto& i : v)
    {
        i.idx = idx++;
        cin >> i.x >> i.y >> i.z;
    }

    sort(v.begin(), v.end(), [](v_data& a, v_data& b)
        {
            return a.x < b.x;
        });

    struct pq_data
    {
        int u;
        int v;
        int dist;

        bool operator < (const pq_data& rhs) const
        {
            return dist > rhs.dist;
        }
    };

    priority_queue<pq_data> pq;
    for (int i = 0; i < N - 1; i++)
        pq.push({ v[i].idx,v[i + 1].idx,abs(v[i].x - v[i + 1].x) });

    sort(v.begin(), v.end(), [](v_data& a, v_data& b)
        {
            return a.y < b.y;
        });
    
    for (int i = 0; i < N - 1; i++)
        pq.push({ v[i].idx,v[i + 1].idx,abs(v[i].y - v[i + 1].y) });

    sort(v.begin(), v.end(), [](v_data& a, v_data& b)
        {
            return a.z < b.z;
        });

    for (int i = 0; i < N - 1; i++)
        pq.push({ v[i].idx,v[i + 1].idx,abs(v[i].z - v[i + 1].z) });

    disjoint_set d_set(N + 1);

    int total = 0;
    while (!pq.empty())
    {
        int u = pq.top().u;
        int v = pq.top().v;
        int c = pq.top().dist;
        pq.pop();

        if (d_set.merge(u, v))
        {
            total += c;
        }
    }
    cout << total << '\n';
}