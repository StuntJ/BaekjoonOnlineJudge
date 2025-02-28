#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<bool>> v(N + 1, vector<bool>(N + 1,true));
	vector<vector<int>> adj(N + 1);

	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1) break;

		v[a][b] = false;
		v[b][a] = false;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)	
			if (v[i][j]) adj[i].emplace_back(j);
		
	
	vector<int> rec[2];
	vector<bool> visited(N + 1);

	auto dfs = [&](auto& dfs, int here, int level)->void
		{
			rec[level % 2].emplace_back(here);
			visited[here] = true;

			for (auto next : adj[here])
			{
				if (!visited[next])
					dfs(dfs, next, level + 1);
			}
		};

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			dfs(dfs, i, 0);
		}
	}

	for (int i = 0; i < 2; i++) sort(rec[i].begin(), rec[i].end());

	if (rec[1].size() == 0)
	{
		cout << 1 << '\n';
		cout << rec[0][0] << ' ' << -1 << '\n';
		for (int i = 1; i < rec[0].size(); i++)
		{
			cout << rec[0][i] << ' ';
		}
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < rec[i].size(); j++)
		{
			int ob = rec[i][j];
			bool flag = true;
			for (int k = j + 1; k < rec[i].size(); k++)
			{
				int num = rec[i][k];
				if (v[ob][num]==true)
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << 1 << '\n';
	for (auto i : rec[0]) cout << i << ' ';
	cout << -1 << '\n';
	for (auto i : rec[1]) cout << i << ' ';
	cout << -1 << '\n';
}