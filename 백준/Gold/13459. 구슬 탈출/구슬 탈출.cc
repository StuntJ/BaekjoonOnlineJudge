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

    struct rt_data
    {
        pi R;
        pi B;

        bool operator < (const rt_data& rhs) const
        {
            if (R == rhs.R)
                return B < rhs.B;
            else return R < rhs.R;
        }
    };

    int N, M;
    cin >> N >> M;

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    vvc grid(N, vc(M));

    pi R, B;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') R = { i,j };
            else if (grid[i][j] == 'B') B = { i,j };
        }
    }

    auto move = [&](vvc& bd, pi R, pi B, int dx, int dy)->rt_data
        {
            bool flag = false;
            if (dx == 1 && R.second == B.second && R.first < B.first) flag = true;
            if (dx == -1 && R.second == B.second && R.first > B.first) flag = true;
            if (dy == 1 && R.first == B.first && R.second < B.second) flag = true;
            if (dy == -1 && R.first == B.first && R.second > B.second) flag = true;

            if (flag) //B먼저 움직임
            {
                int x = B.first;
                int y = B.second;
                while (true)
                {
                    if (bd[x + dx][y + dy] == '#' || bd[x + dx][y + dy] == 'R') break;
                    if (bd[x + dx][y + dy] == 'O')
                    {
                        x = -1;
                        y = -1;
                        break;
                    }
                    x += dx;
                    y += dy;
                }
                if (x != -1) swap(bd[x][y], bd[B.first][B.second]);
                else bd[B.first][B.second] = '.';
                B = { x,y };

                x = R.first;
                y = R.second;
                while (true)
                {
                    if (bd[x + dx][y + dy] == '#' || bd[x + dx][y + dy] == 'B') break;
                    if (bd[x + dx][y + dy] == 'O')
                    {
                        x = -1;
                        y = -1;
                        break;
                    }
                    x += dx;
                    y += dy;
                }
                if (x != -1) swap(bd[x][y], bd[R.first][R.second]);
                else bd[R.first][R.second] = '.';
                R = { x,y };
            }
            else
            {
                int x = R.first;
                int y = R.second;
                while (true)
                {
                    if (bd[x + dx][y + dy] == '#' || bd[x + dx][y + dy] == 'B') break;
                    if (bd[x + dx][y + dy] == 'O')
                    {
                        x = -1;
                        y = -1;
                        break;
                    }
                    x += dx;
                    y += dy;
                }
                if (x != -1) swap(bd[x][y], bd[R.first][R.second]);
                else bd[R.first][R.second] = '.';
                R = { x,y };

                x = B.first;
                y = B.second;
                while (true)
                {
                    if (bd[x + dx][y + dy] == '#' || bd[x + dx][y + dy] == 'R') break;
                    if (bd[x + dx][y + dy] == 'O')
                    {
                        x = -1;
                        y = -1;
                        break;
                    }
                    x += dx;
                    y += dy;
                }
                if (x != -1) swap(bd[x][y], bd[B.first][B.second]);
                else bd[B.first][B.second] = '.';
                B = { x,y };
            }
            return { R,B };
        };

    int depth = 11;
    map<rt_data, int> mp;
    auto solve = [&](auto& solve, int n, pi R, pi B, vvc& grid) ->int
        {
            rt_data here;
            here.B = B;
            here.R = R;
            if (mp.find(here) != mp.end()) if (mp[here] <= n) return 11;
            if (n >= depth) return 11;
            if (B == make_pair(-1, -1)) return 11;
            if (R == make_pair(-1, -1))
            {
                depth = min(depth, n);
                return n;
            }
            if (mp.find(here) == mp.end()) mp.insert(make_pair(here, n));
            else mp[here] = n;

            int ret = 11;
            for (int i = 0; i < 4; i++)
            {
                vvc cp = grid;
                rt_data k = move(cp, R, B, dx[i], dy[i]);
                ret = min(ret, solve(solve, n + 1, k.R, k.B, cp));
            }
            return ret;
        };

    int ans = solve(solve, 0, R, B, grid);
    if (ans == 11) cout << 0 << '\n';
    else cout << 1 << '\n';
}