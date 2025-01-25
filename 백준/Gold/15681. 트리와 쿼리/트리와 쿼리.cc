#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dp;

void treeDp(int here)
{
	visited[here] = true;
	for (auto next : adj[here])
	{
		if (!visited[next])
		{
			treeDp(next);
			dp[here] += dp[next];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, R, Q;
	cin >> N >> R >> Q;
	adj.resize(N + 1);
	visited.assign(N + 1, false);
	dp.assign(N + 1, 1);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	treeDp(R);
	for (int i = 0; i < Q; i++)
	{
		int x;
		cin >> x;
		cout << dp[x] << '\n';
	}
}