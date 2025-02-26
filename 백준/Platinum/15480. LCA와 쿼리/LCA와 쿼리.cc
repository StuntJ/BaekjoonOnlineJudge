#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int lim = (int)floor(log2(N));

	vector<vector<int>> adj(N + 1);
	vector<vector<int>> dp(lim + 1, vector<int>(N + 1));
	vector<int> depth(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	auto dfs = [&](auto& dfs, int here, int p = -1)->void
	{
		for (auto next : adj[here])
		{
			if (p != next)
			{
				depth[next] = depth[here] + 1;
				dp[0][next] = here;
				dfs(dfs, next, here);
			}
		}
	};

	auto makeTable = [&]()->void
	{
		for (int i = 1; i <= lim; i++)
			for (int j = 1; j <= N; j++)
				dp[i][j] = dp[i - 1][dp[i - 1][j]];
	};

	auto lca = [&](int a, int b)->int
	{
		if (depth[a] < depth[b]) swap(a, b);
		int diff = depth[a] - depth[b];

		for (int i = 0; diff; i++)
		{
			if (diff & 1) a = dp[i][a];
			diff >>= 1;
		}

		for (int i = lim; i >= 0; i--)
			if (dp[i][a] != dp[i][b]) 
				a = dp[i][a], b = dp[i][b];
		
		if (a == b) return a;
		return dp[0][a];
	};

	dfs(dfs, 1);
	makeTable();

	int Q;
	cin >> Q;
	
	while (Q--)
	{
		int r, u, v;
		cin >> r >> u >> v;
		int ru = lca(r, u);
		int rv = lca(r, v);
		int uv = lca(u, v);

		if (depth[rv] >= depth[ru] && depth[rv] >= depth[uv]) cout << rv << '\n';
		else if (depth[ru] >= depth[uv] && depth[ru] >= depth[rv]) cout << ru << '\n';
		else cout << uv << '\n';
	}
}