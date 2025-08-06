#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> depth;
int V;

void dfs(int src, int d)
{
	visited[src] = true;
	depth[src] = d;
	for (auto next : adj[src])
	{
		if (visited[next]) continue;
		dfs(next, d + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V;

	adj.resize(V);
	visited.assign(V, false);
	depth.assign(V, 0);

	for (int i = 0; i < V-1; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 0);
	/*for (auto k : depth) cout << k << ' ';
	cout << '\n';*/

	for (int i = V - 1; i >= 1; i--)
	{
		if ((V - 1 - (depth[i])) % 2 == 0) cout << 0;
		else cout << 1;
	}
}