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

    int T;
    cin >> T;
    while (T--)
    {
        int H, W;
        cin >> H >> W;

        vvc grid(H, vc(W));

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> grid[i][j];

        string str;
        cin >> str;
        vvpi rec(26);
        queue<char> alpha;
        queue<pi> q;
        vvb visited(H, vb(W));
        for (auto ch : str)
        {
            if (ch == '0') continue;
            alpha.push(ch);
        }
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && (grid[i][j] == '.' || grid[i][j] == '$' || ('a' <= grid[i][j] && grid[i][j] <= 'z')))
                {
                    visited[i][j] = true;
                    q.push({ i,j });
                }
                if (grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                    rec[grid[i][j] - 'A'].push_back({ i,j });
            }
        }
        
        auto isInrange = [&](int x, int y)
            {
                return 0 <= x && x < H && 0 <= y && y < W;
            };

        int dx[4] = { 0,0,1,-1 };
        int dy[4] = { 1,-1,0,0 };
        int ans = 0;

        while (!alpha.empty())
        {
            char ch = alpha.front();
            alpha.pop();
            for (auto cd : rec[ch - 'a'])
            {
                int x = cd.first;
                int y = cd.second;

                for (int i = 0; i < 4; i++)
                {

                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (!isInrange(nx, ny)) continue;

                    if ((x == 0 || x == H - 1 || y == 0 || y == W - 1) || visited[nx][ny])
                    {
                        q.push({ x,y });
                        visited[x][y] = true;
                        break;
                    }
                }
                grid[x][y] = '.';
            }
        }

        while (!q.empty())
        {
            pi cd = q.front(); q.pop();
            if (grid[cd.first][cd.second] == '$') ans++;
            else if (grid[cd.first][cd.second] >= 'a' && grid[cd.first][cd.second] <= 'z') alpha.push(grid[cd.first][cd.second]);
            
            for (int i = 0; i < 4; i++)
            {
                int nx = cd.first + dx[i];
                int ny = cd.second + dy[i];

                if (!isInrange(nx, ny) || visited[nx][ny]) continue;
                if (grid[nx][ny] == '.' || 'a' <= grid[nx][ny] && grid[nx][ny] <= 'z'||grid[nx][ny]=='$')
                {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }

            while (!alpha.empty())
            {
                char ch = alpha.front();
                alpha.pop();
                for (auto cd : rec[ch - 'a'])
                {
                    int x = cd.first;
                    int y = cd.second;

                    for (int i = 0; i < 4; i++)
                    {
        
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (!isInrange(nx, ny)) continue;

                        if ((x == 0 || x == H - 1 || y == 0 || y == W - 1) || visited[nx][ny])
                        {
                            q.push({ x,y });
                            visited[x][y] = true;
                            break;
                        }
                    }
                    grid[x][y] = '.';
                }
            }
        }
        cout << ans << '\n';
    }
}