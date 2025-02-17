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
        int N;
        cin >> N;
        vvi adj(N + 1);
        vi inDegree(N + 1);

        for (int i = 1; i <= N; i++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
            inDegree[x]++;
        }

        queue<int> q;
        for (int i = 1; i <= N; i++)
        {
            if (inDegree[i] == 0) q.push(i);
        }

    
        while (!q.empty())
        {
            int here = q.front(); q.pop();

            for (auto next : adj[here])
                if (--inDegree[next] == 0) q.push(next);
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            if (inDegree[i] == 0) cnt++;
        }
        cout << cnt << '\n';
    }
}