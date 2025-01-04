#include <bits/stdc++.h>
#define ROOT 1

using namespace std;

struct FenwickTree
{
	vector<int> B;
	FenwickTree(int n)
	{
		B.resize(n + 1);
	}

	int sum(int pos)
	{
		pos++;
		int ret = 0;
		while (pos > 0)
		{
			ret += B[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void update(int pos, int val)
	{
		pos++;
		while (pos < B.size())
		{
			B[pos] += val;
			pos += (pos & -pos);
		}
	}

	void update(int left, int right, int val)
	{
		update(left, val);
		if (right < B.size() - 2) update(right + 1, -val);
	}
};

void dfs(const vector<vector<int>>& adj, vector<int>& newIdx, vector<int>& end, int& cnt, int src)
{
	int hereCnt = newIdx[src] = ++cnt;
	for (auto next : adj[src])
		dfs(adj, newIdx, end, cnt, next);
	end[hereCnt] = cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N + 1);
	vector<int> newIdx(N + 1);
	vector<int> end(N);

	for (int i = 1; i <= N; i++)
	{
		int parent;
		cin >> parent;
		if (parent == -1) continue;
		adj[parent].emplace_back(i);
	}

	int cnt = -1;
	dfs(adj, newIdx, end, cnt, ROOT);

	/*for (auto i : newIdx) cout << i << ' ';
	cout << '\n';
	for (auto i : end) cout << i << ' ';
	cout << '\n';*/

	FenwickTree seg(N);

	while (M--)
	{
		int qu;
		cin >> qu;
		if (qu == 1)
		{
			int i, w;
			cin >> i >> w;
			int s = newIdx[i];
			int e = end[s];
			seg.update(s, e, w);
		}
		else
		{
			int i;
			cin >> i;
			int idx = newIdx[i];
			cout << seg.sum(idx) << '\n';
		}
	}
}