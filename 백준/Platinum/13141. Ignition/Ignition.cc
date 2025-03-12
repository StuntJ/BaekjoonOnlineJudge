#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int s;
	int e;
	int cost;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int INF = 987654321;
	int N, M;
	cin >> N >> M;

	vector<edge> eg;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1,INF));

	for (int i = 0; i < M; i++)
	{
		int S, E, L;
		cin >> S >> E >> L;

		eg.push_back({ S,E,2*L });
		adj[S][E] = min(adj[S][E],2*L);
		adj[E][S] = min(adj[S][E],2*L);
	}
	for (int i = 1; i <= N; i++)
		adj[i][i] = 0;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << adj[i][j] << ' ';
		cout << '\n';
	}*/
	
	int ans = INF;
	for (int i = 1; i <= N; i++)
	{
		int Ttime = 0;
		for (auto p : eg)
		{
			int s = p.s;
			int e = p.e;
			int cost = p.cost;

			if (adj[i][s] > adj[i][e]) swap(s, e);

			int diff = adj[i][e] - adj[i][s];
			int t = adj[i][s] + diff + (cost - diff) / 2;
			Ttime = max(Ttime, t);
		}
		ans = min(ans, Ttime);
		//cout << Ttime << '\n';
	}

	cout << fixed;
	cout.precision(1);

	cout << (double)ans/2 << '\n';
	
}