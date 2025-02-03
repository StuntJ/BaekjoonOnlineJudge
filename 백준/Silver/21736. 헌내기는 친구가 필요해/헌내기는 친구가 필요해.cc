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

    vvc board = vvc(N, vc(M));

    auto isInrange = [&](int x, int y)
        {
            return 0 <= x && x < N && 0 <= y && y < M;
        };

    int stx, sty;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'I')
            {
                stx = i;
                sty = j;
            }
        }
    }

    vvb visited = vvb(N, vb(M, 0));
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    function<int(int, int)> dfs = [&](int x, int y) ->int
        {
            visited[x][y] = true;
            int ret = (board[x][y] == 'P' ? 1 : 0);
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!isInrange(nx, ny) || visited[nx][ny]|| board[nx][ny] == 'X') continue;
                ret += dfs(nx, ny);
            }
            return ret;
        };

    int ans  = dfs(stx, sty);
    if (ans == 0) cout << "TT" << '\n';
    else cout << ans << '\n';
}