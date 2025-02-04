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

    const int lim = 101;

    int N, M;
    cin >> N >> M;

    vi go(lim);
    for (int i = 1; i < lim; i++) go[i] = i;
    vb visited(lim);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        go[a] = b;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        go[a] = b;
    }

    visited[1] = true;
    struct q_data
    {
        int x;
        int dist;
    };
    auto isInrange = [&](int x)
        {
            return x < lim;
        };

    queue<q_data> q;
    q.push({ 1,0 });

    while (!q.empty())
    {
        q_data here = q.front();
        q.pop();

        if (here.x == 100)
        {
            cout << here.dist;

            return 0;
        }

        for (int i = 1; i <= 6; i++)
        {
            int nx = here.x + i;
            if (isInrange(nx) && !visited[go[nx]])
            {
                q.push({ go[nx],here.dist + 1 });
                visited[go[nx]] = true;
            }
        }
    }

}