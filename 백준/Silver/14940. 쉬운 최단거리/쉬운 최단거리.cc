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
    int stx, sty;
    vvi grid(N, vi(M));
    vvb visited(N, vb(M));
    vvi rec(N, vi(M,-1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2) stx = i, sty = j;
            else if (grid[i][j] == 0) rec[i][j] = 0;
        }
    }

    auto isInrange = [&](int x, int y)
        {
            return 0 <= x && x < N && 0 <= y && y < M;
        };

    struct q_data
    {
        int x;
        int y;
        int dist;
    };

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    queue<q_data> q;
    q.push({ stx,sty,0 });
    rec[stx][sty] = 0;
    visited[stx][sty] = true;
    while (!q.empty())
    {
        q_data here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = here.x + dx[i];
            int ny = here.y + dy[i];

            if (!isInrange(nx, ny)) continue;
            if (visited[nx][ny]||grid[nx][ny]==0) continue;
            
            visited[nx][ny] = true;
            rec[nx][ny] = here.dist + 1;
            q.push({ nx,ny,here.dist + 1 });
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << rec[i][j] << ' ';
        }
        cout << '\n';
    }
}