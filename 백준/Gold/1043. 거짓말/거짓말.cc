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

    int K;
    cin >> K;
    vi v(K);
    for (auto& i : v) cin >> i;

    vvi adj = vvi(N + 1);
    vvi party = vvi(M);

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        int a;
        cin >> a;
        party[i].emplace_back(a);
        for (int j = 0; j < num - 1; j++)
        {
            int b;
            cin >> b;
            party[i].emplace_back(b);

            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
    }

    vb chk(N + 1,false);

    auto dfs = [&](auto& dfs, int here, vb& visited) -> void
        {
            visited[here] = true;
            chk[here] = true;
            for (auto next : adj[here])
            {
                if (visited[next]) continue;
                dfs(dfs, next, visited);
            }
        };

    for (auto i : v)
    {
        vb visited(N + 1);
        dfs(dfs, i, visited);
    }

    int cnt = M;
    for (int i = 0; i < M; i++)
    {
        for (auto j : party[i])
        {
            if (chk[j])
            {
                cnt--;
                break;
            }
        }
    }
    cout << cnt << '\n';
    
}