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

struct status
{
    int r;
    int c;
    int d;
    int v;
    int s;
};

typedef vector<status> vs;
typedef vector<vs> vvs;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C, M;
    cin >> R >> C >> M;

    queue<status> q;
    int dx[5] = { 0,-1,1,0,0 };
    int dy[5] = { 0,0,0,1,-1 };

    int closeSize = 0;
    int clDist = 1000;

    for (int i = 0; i < M; i++)
    {
        int r, c, v, d, s;
        cin >> r >> c >> v >> d >> s;

        if(c==1)
        {
            int dist = r;

            if (clDist > dist)
            {
                clDist = dist;
                closeSize = s;
            }
        }
        
        q.push({ r,c,d,v,s });
    }

    int qsz = q.size();
    for (int i = 0; i < qsz; i++)
    {
        status here = q.front(); q.pop();
        if (here.s != closeSize)
        {
            q.push(here);
        }
    }

    int total = 0;
    status blank = { 0,0,0 };
    vvi grid(R + 1, vi(C + 1));
    int udt = (R - 1) * 2;
    int lrt = (C - 1) * 2;

    for (int i = 1; i < C; i++)
    {
        pi fisherCd = { 0,i+1 };
        total += closeSize;

        clDist = 1000;
        closeSize = 0;

        int sz = q.size();
        for (int j = 0; j < sz; j++)
        {
            status here = q.front(); q.pop();
            grid[here.r][here.c] = 0;
            if (here.d < 3)
            {
                int mv = here.v;
                mv %= udt;
                int &md = here.d;
                while (true)
                {
                    if (mv <= 0) break;
                    if (md == 1)
                    {
                        int tom = here.r - 1;
                        here.r -= min(mv, tom);
                        mv -= tom;
                        if(mv>=0)
                            md = 2;
                    }
                    else
                    {
                        int tom = R - here.r;
                        here.r += min(mv, tom);
                        mv -= tom;
                        if(mv>=0)
                        md = 1;
                    }
                }
            }
            else
            {
                int mv = here.v;
                mv %= lrt;
                int &md = here.d;
                while (true)
                {
                    if (mv <= 0) break;
                    if (md == 3)
                    {
                        int tom = C - here.c;
                        here.c += min(mv, tom);
                        mv -= tom;
                        if(mv>=0)
                            md = 4;
                    }
                    else
                    {
                        int tom = here.c - 1;
                        here.c -= min(mv, tom);
                        mv -= tom;
                        if(mv>=0)
                        md = 3;
                    }
                }
            }
            q.push(here);
        }

        for (int j = 0; j < sz; j++)
        {
            status here = q.front(); q.pop();
            grid[here.r][here.c]= max(grid[here.r][here.c], here.s);
            q.push(here);
        }

        for (int j = 0; j < sz; j++)
        {
            status here = q.front(); q.pop();
            if (grid[here.r][here.c] == here.s)
            {
                q.push(here);
                if(here.c == i+1)
                {
                    int dist = here.r;
                    if (clDist > dist)
                    {
                        clDist = dist;
                        closeSize = here.s;
                    }
                }
            }
        }

        sz = q.size();
        for (int j = 0; j < q.size(); j++)
        {
            status here = q.front(); q.pop();
            if (here.s == closeSize)
            {
                grid[here.r][here.c] = 0;
            }
            else q.push(here);
        }

        /*cout << total << '\n';
        for (int j = 1; j <= R; j++)
        {
            for (int k = 1; k <= C; k++)
            {
                cout << grid[j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';*/
    }
    cout << total+closeSize << '\n';
}