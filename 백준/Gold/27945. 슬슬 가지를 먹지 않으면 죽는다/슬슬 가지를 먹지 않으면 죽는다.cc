#include <bits/stdc++.h>

using namespace std;

struct disjoint_set
{
	vector<int> parent, rank;
	disjoint_set(int n)
	{
		parent.resize(n + 1);
		rank.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	bool merge(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (rank[a] > rank[b]) swap(a, b);
		parent[a] = b;
		if (rank[a] == rank[b]) rank[b]++;
		return true;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	vector<pair<int, pair<int, int>>> data(M);
	for (int i = 0; i < M; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;

		data[i] = make_pair(t, make_pair(u, v));
	}
	sort(data.begin(), data.end());

	int cnt = 1;
	disjoint_set d_set(N);
	for (int i = 0; i < M ; i++)
	{
		if (data[i].first != (i + 1)) break;
		if (!d_set.merge(data[i].second.first, data[i].second.second)) break;
		cnt++;
	}
	cout << cnt;
}