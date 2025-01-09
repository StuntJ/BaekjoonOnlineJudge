#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		double p;
		cin >> p;
		int N;
		cin >> N;
		vector<vector<int>> adj(N, vector<int>(N));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> adj[i][j];
				if (adj[i][j] == -1)
				{
					adj[i][j] = INF;
				}
			}
		}

		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << adj[i][j] << ' ';
			cout << '\n';
		}*/
		vector<int> ans;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (i != j) ans.emplace_back(adj[i][j]);

		sort(ans.begin(), ans.end());

		int tot = ans.size();
		cout << "Scenario #" << t << ":\n";
		for (int i = 0; i < tot; i++)
		{
			if ((double)(i + 1) / tot * 100.0 >= p)
			{
				cout << ans[i] << '\n';
				break;
			}
		}
		cout << '\n';
	}
}