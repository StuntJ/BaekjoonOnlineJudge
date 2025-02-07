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
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vvpll adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[b].emplace_back(make_pair(c, a));
    }

    const ll INF = 1000000000000000000;
    vll dist(N + 1, INF);
    priority_queue<pll, vpll, greater<pll>> pq;
    for (int i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        dist[x] = 0;
        pq.push({ 0,x });
    }

    while (!pq.empty())
    {
        ll here = pq.top().second;
        ll hereDist = pq.top().first;
        pq.pop();

        if (hereDist > dist[here]) continue;

        for (auto next : adj[here])
        {
            ll nextDist = hereDist + next.first;
            ll nextV = next.second;

            if (nextDist > dist[nextV]) continue;
            dist[nextV] = nextDist;
            pq.push({ nextDist,nextV });
        }
    }

    ll maximum = -1;
    int idx = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] > maximum)
        {
            idx = i;
            maximum = dist[i];
        }
    }
    cout << idx << '\n' << maximum << '\n';
}