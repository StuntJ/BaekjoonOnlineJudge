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
    vvi grid(N, vi(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char x;
            cin >> x;
            if (x == '1') grid[i][j] = -1;
            else grid[i][j] = 0;
        }
    }

    stack<pi> st;

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    auto isInrange = [&](int x, int y)
        {
            return 0 <= x && x < N && 0 <= y && y < M;
        };

    auto dfs = [&](auto& dfs, int x, int y)->void
        {
            grid[x][y] = -1;
            st.push({ x,y });

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isInrange(nx,ny) && grid[nx][ny] == 0)
                {
                    dfs(dfs, nx, ny);
                }
            }
        };

    vvi fam(N, vi(M));
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 0)
            {
                dfs(dfs, i, j);
                int sz = st.size();
                while (!st.empty())
                {
                    pi cd = st.top(); st.pop();
                    grid[cd.first][cd.second] = sz;
                    fam[cd.first][cd.second] = idx;
                }
                idx++;
            }
        }
    }

    vvi ans(N, vi(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == -1)
            {
                int tot = 1;
                set<int> sp;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (!isInrange(nx, ny) || grid[nx][ny] == -1||sp.find(fam[nx][ny])!=sp.end()) continue;
                    tot += grid[nx][ny];
                    sp.insert(fam[nx][ny]);
                }
                ans[i][j] = tot;
            }
            else ans[i][j] = 0;
        }
    }

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //        cout << grid[i][j];
    //    cout << '\n';
    //}
    //cout << '\n';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << ans[i][j]%10;
        cout << '\n';
    }
}