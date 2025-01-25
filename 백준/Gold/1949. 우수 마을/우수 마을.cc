#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> cost;
vector<bool> visited;
vector<vector<int>> adj;
vector<vector<int>> cache;

int solve(int n, int isTrue, int parent = -1)
{
    int& ret = cache[n][isTrue];
    if (ret != -1) return ret;
    ret = 0;
    for (auto next : adj[n])
    {
        int temp = 0;
        if (next!=parent)
        {
            temp = max(temp, solve(next, 0, n));
            if (!isTrue)
            {
                temp = max(temp, solve(next, 1,n) + cost[next]);
            }
          
        }
        ret += temp;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cost = vector<int>(N);
    for (auto& i : cost) cin >> i;
    cost.insert(cost.begin(), 0);
    visited = vector<bool>(N + 1);
    adj = vector<vector<int>>(N + 1);
    cache = vector<vector<int>>(N + 1, vector<int>(2, -1));

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    int ret = 0;
    ret = cost[1] + solve(1, true);
    visited = vector<bool>(N + 1, false);
    ret = max(ret, solve(1, false));
    cout << ret << '\n';
}