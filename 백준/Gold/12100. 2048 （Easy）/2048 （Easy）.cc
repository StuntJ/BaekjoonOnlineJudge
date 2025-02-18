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

const int LIM = 5;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vvi grid(N, vi(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    auto mg = [&](vi& temp)
        {
            vi res;
            for (int i = 0; i < temp.size(); i++)
            {
                if (i + 1 < temp.size() && temp[i] == temp[i + 1])
                {
                    res.emplace_back(temp[i] * 2);
                    i++;
                }
                else
                    res.emplace_back(temp[i]);
            }
            return res;
        };

    auto up = [&](vvi& vv)
        {
            for (int j = 0; j < N; j++)
            {
                vi temp;
                for (int i = 0; i < N; i++)
                {
                    if (vv[i][j] != 0) temp.emplace_back(vv[i][j]);
                }
                temp = mg(temp);
                for (int i = 0; i < N; i++)
                {
                    if (i < temp.size()) vv[i][j] = temp[i];
                    else vv[i][j] = 0;
                }
            }
        };

    auto down = [&](vvi& vv)
        {
            for (int j = 0; j < N; j++)
            {
                vi temp;
                for (int i = N-1; i >=0 ; i--)
                {
                    if (vv[i][j] != 0) temp.emplace_back(vv[i][j]);
                }
                temp = mg(temp);
                for (int i = N-1; i >=0 ; i--)
                {
                    if (N-i-1 < temp.size()) vv[i][j] = temp[N-i-1];
                    else vv[i][j] = 0;
                }
            }
        };

    auto right = [&](vvi& vv)
        {
            for (int i = 0; i < N; i++)
            {
                vi temp;
                for (int j = N - 1; j >= 0; j--)
                {
                    if (vv[i][j] != 0) temp.emplace_back(vv[i][j]);
                }
                temp = mg(temp);
                for (int j = N - 1; j >= 0; j--)
                {
                    if (N - j - 1 < temp.size()) vv[i][j] = temp[N-j-1];
                    else vv[i][j] = 0;
                }
            }
        };

    auto left = [&](vvi& vv)
        {
            for (int i = 0; i < N; i++)
            {
                vi temp;
                for (int j = 0; j < N; j++)
                {
                    if (vv[i][j] != 0) temp.emplace_back(vv[i][j]);
                }
                temp = mg(temp);
                for (int j = 0; j < N; j++)
                {
                    if (j < temp.size()) vv[i][j] = temp[j];
                    else vv[i][j] = 0;
                }
            }
        };

    auto solve = [&](auto& solve, int n, vvi& g) -> int
        {
            if (n == 5)
            {
                int M = 0;
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        M = max(M, g[i][j]);
                return M;
            }

            int ret = 0;
            vvi u = g, d = g, l = g, r = g;

            up(u);
            down(d);
            left(l);
            right(r);
            ret = max(ret,solve(solve, n + 1, u));
            ret = max(ret,solve(solve, n + 1, d));
            ret = max(ret,solve(solve, n + 1, l));
            ret = max(ret,solve(solve, n + 1, r));

            return ret;
        };

    cout << solve(solve, 0, grid);
}