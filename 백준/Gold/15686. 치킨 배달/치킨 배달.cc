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

    int N, M;
    cin >> N >> M;
    vvi grid(N, vi(N));
    vpi c;
    vvi dist;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
                c.push_back({ i,j });
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1)
            {
                vi temp;
                for (int k = 0; k < c.size(); k++)
                {
                    temp.push_back(abs(c[k].first - i) + abs(c[k].second - j));
                }
                dist.push_back(temp);
            }
        }
    }

    int sz = c.size();
    
    const int INF = 987654321;
    vi d(dist.size(), INF);
    auto solve = [&](auto& solve, int here, int m, vi dk)
        {
            if (m == M)
            {
                return accumulate(dk.begin(), dk.end(), 0);
            }
            if (here >= sz) return INF;
            int ret = INF;

            ret = solve(solve, here + 1, m, dk);
            for (int i = 0; i < dist.size(); i++)
            {
                dk[i] = min(dk[i], dist[i][here]);
            }
            ret = min(ret,solve(solve, here + 1, m + 1, dk));
            return ret;
        };

    cout << solve(solve, 0, 0, d);
}