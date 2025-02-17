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

    vvi adj(N + 1);
    vi inDegree(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        vi temp(num);
        for (auto& k : temp) cin >> k;

        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = j + 1; k < temp.size(); k++)
            {
                adj[temp[j]].push_back(temp[k]);
                inDegree[temp[k]]++;
            }
        }
     
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            q.push(i);

    vi ans;
    
    while (!q.empty())
    {
        int here = q.front(); q.pop();
        ans.push_back(here);
        for (auto next : adj[here])
        {
            if (--inDegree[next] == 0) q.push(next);
        }
    }

    if (ans.size() != N) cout << 0 << '\n';
    else for (auto i : ans) cout << i << '\n';
}