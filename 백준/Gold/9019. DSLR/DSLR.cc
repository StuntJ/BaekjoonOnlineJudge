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

const int mod = 10000;

int fL(int x)
{
    return (x % 1000) * 10 + (x / 1000);
}

int fR(int x)
{
    return (x % 10) * 1000 + (x / 10);
}

int fD(int x)
{
    return x * 2 % mod;
}

int fS(int x)
{
    return (x + mod - 1) % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vvpi adj(mod);
    for (int i = 0; i < mod; i++)
    {
        adj[i].emplace_back(make_pair(fD(i),0));
        adj[i].emplace_back(make_pair(fS(i),1));
        adj[i].emplace_back(make_pair(fL(i),2));
        adj[i].emplace_back(make_pair(fR(i),3));
    }

    while(T--)
    {
        vb visited(mod);
        int a, b;
        cin >> a >> b;

        struct q_data
        {
            int x;
            string str;
        };

        queue<q_data> q;
        q.push({ a,""});
        visited[a] = true;
        string enu = "DSLR";
        while (!q.empty())
        {
            q_data here = q.front(); q.pop();
            if (here.x == b)
            {
                cout << here.str << '\n';
                break;
            }

            for (auto next : adj[here.x])
            {
                if (!visited[next.first])
                {
                    visited[next.first] = true;
                    q.push({next.first ,here.str+enu[next.second]});
                }
            }
        }
    }
}