#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v) cin >> i;
	v.insert(v.begin(), 0);
	vector<vector<int>> adj(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	auto dfs = [&](auto& dfs, int here, int p=-1)->int
		{
			int ret = 0;
			for (auto next : adj[here])
			{
				if (next == p) continue;
				if (v[here] != v[next]) ret++;
				ret += dfs(dfs, next, here);
			}
			return ret;
		};
	cout << dfs(dfs, 1) + (v[1] ? 1 : 0);
}