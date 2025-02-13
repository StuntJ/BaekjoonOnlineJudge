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

    vvi grid(9, vi(9));
    vvc input(9, vc(9));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> input[i][j];
            grid[i][j] = input[i][j] - '0';
        }
    }

    auto solve = [&](auto& solve, vvi& grid)->void
        {
            int chx = -1, chy = -1;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (grid[i][j] == 0) chx = i, chy = j;
                    if (chx != -1) break;
                }
                if (chx != -1) break;
            }

            if (chx == -1)
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        cout << grid[i][j];
                    }
                    cout << '\n';
                }
                exit(0);
            }

            vb cand(10);

            for (int i = 0; i < 9; i++)
            {
                if (chx == i) continue;
                cand[grid[i][chy]] = true;
            }
            for (int j = 0; j < 9; j++)
            {
                if (chy == j) continue;
                cand[grid[chx][j]] = true;
            }
            int x = chx / 3 * 3;
            int y = chy / 3 * 3;
            for (int i = x; i < x + 3; i++)
            {
                for (int j = y; j < y + 3; j++)
                {
                    if (chx == x && chy == y) continue;
                    cand[grid[i][j]] = true;
                }
            }

            vi cd;
            for (int i = 1; i <= 9; i++)
                if (!cand[i]) cd.push_back(i);

            for (auto num : cd)
            {
                grid[chx][chy] = num;
                solve(solve, grid);
                grid[chx][chy] = 0;
            }
        };
    solve(solve, grid);
}