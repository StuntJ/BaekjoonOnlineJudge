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
    vvc grid(N, vc(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    auto getDir = [&](char d)->pi
        {
            if (d == 'D') return { 1,0 };
            else if (d == 'U') return { -1,0 };
            else if (d == 'L') return { 0,-1 };
            else return { 0,1 };
        };

    vvb visited(N, vb(M));
    vvb inQ(N, vb(M));

    int cnt = 0;
    auto dfs = [&](auto& dfs, int x, int y)->void
        {
            visited[x][y] = true;
            inQ[x][y] = true;

            int nx = x+getDir(grid[x][y]).first;
            int ny = y + getDir(grid[x][y]).second;
            
            if (inQ[nx][ny]) cnt++;
            if (!visited[nx][ny]) dfs(dfs, nx, ny);
            inQ[x][y] = false;
        };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
                dfs(dfs, i, j);
        }
    }
    cout << cnt;
}