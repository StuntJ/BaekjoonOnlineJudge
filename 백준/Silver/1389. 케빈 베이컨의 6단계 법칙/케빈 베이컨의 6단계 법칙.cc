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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    const int INF = 987654321;
    vvi adj(N, vi(N,INF));

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
    }

    
    for (int i = 0; i < N; i++)
        adj[i][i] = 0;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

   /* for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << adj[i][j] << ' ';
        cout << '\n';
    }*/

    int mn = INF;;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = accumulate(adj[i].begin(), adj[i].end(), 0);
        if (sum < mn)
        {
            mn = sum;
            ans = i + 1;
        }
    }
    cout << ans << '\n';
}