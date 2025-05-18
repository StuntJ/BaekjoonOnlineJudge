#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
#include <array>
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING

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

    int dx[6] = { 0,0,0,0,1,-1 };
    int dy[6] = { 0,0,1,-1,0,0 };
    int dz[6] = { 1,-1,0,0,0,0 };
    while(true)
    {
        int L, R, C;
        cin >> L >> R >> C;
        if (L == 0) return 0;

        vvvc g(L, vvc(R, vc(C)));
        array<int, 3> S, E;

        //string buf;
        for (int i = 0; i < L; i++)
        {
            //if (i != 0) cin >> buf;
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> g[i][j][k];
                    if (g[i][j][k] == 'S') S = { i,j,k };
                    if (g[i][j][k] == 'E') E = { i,j,k };
                }
            }
        }

        vvvb visited(L, vvb(R, vb(C)));
        visited[S[0]][S[1]][S[2]] = true;
        struct q_data {
            array<int, 3> coord;
            int dist;
        };
        queue<q_data> q;
        q.push({ S,0 });
        bool flag = false;
        while (!q.empty())
        {
            auto [x, y, z] = q.front().coord;
            int hereDist = q.front().dist;


            if (E == q.front().coord)
            {
                cout << "Escaped in " << hereDist << " minute(s).\n";
                flag = true;
                break;
            }

            q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if (0 <= nx && nx < L && 0 <= ny && ny < R && 0 <= nz && nz < C)
                {
                    if (!visited[nx][ny][nz]&&g[nx][ny][nz]!='#')
                    {
                        visited[nx][ny][nz] = true;
                        q.push({ {nx,ny,nz},hereDist + 1 });
                    }
                }
            }
        }
        if(!flag)
            cout << "Trapped!\n";
    }
}