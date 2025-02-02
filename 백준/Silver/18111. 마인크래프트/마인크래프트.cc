#include <bits/stdc++.h>
#define int long long

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

const int INF = 1000000000000000000;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, B;
    cin >> N >> M >> B;
    vvi grid = vvi(N, vi(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    int maxHeight = 0;
    int minTime = INF;
    for (int i = 0; i <= 256; i++)
    {
        int time = 0;
        int got = B;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int p = grid[j][k] - i;
                if(p>0)
                {

                    time += 2 * p;
                    got += p;

                }
                
            }
        }
        bool can = true;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int p = i - grid[j][k];
                if(p>0)
                {
                    time += p;
                    got -= p;
                    if (got < 0) can = false;
                    
                }
                
            }
        }
        if (!can) continue;
        if (minTime >= time)
        {
            minTime = time;
            maxHeight = i;
        }
    }
    cout << minTime << ' ' << maxHeight;
}