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

const int INF = 987654321;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    vvpi adj(N+1);
    for (int i = 0; i < M; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].emplace_back(make_pair(d,b));
    }

    vi distAll(N + 1, -1);
    vi rev;
    for (int i = 1; i <= N; i++)
    {
        vi dist(N + 1,INF);
        priority_queue<pair<int, int>> pq;
        dist[i] = 0;
        pq.push({0,i});

        while (!pq.empty())
        {
            int here = pq.top().second;
            int hereDist = -pq.top().first;
            pq.pop();

            if (hereDist > dist[here]) continue;

            for (auto next : adj[here])
            {
                int nextDist = hereDist + next.first;
                if (nextDist < dist[next.second])
                {
                    dist[next.second] = nextDist;
                    pq.push({ -nextDist,next.second });
                }
            }
        }

        if (i == X) rev = dist;
        else
        {
            distAll[i] = dist[X];
        }
    }

    int maxVal = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == X) continue;
        int res = distAll[i] + rev[i];
        maxVal = max(maxVal, res);
    }
    cout << maxVal;
}