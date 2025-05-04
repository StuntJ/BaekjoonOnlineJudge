#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> adj(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(make_pair(c, b));
		adj[b].emplace_back(make_pair(c, a));
	}

	const int INF = 987654321;
	priority_queue<pair<int, int>> pq;
	vector<int> dist(N + 1,INF);
	int S, E;
	cin >> S >> E;
	dist[S] = 0;
	pq.push({ 0,S });
	while (!pq.empty())
	{
		int here = pq.top().second;
		int hereDist = -pq.top().first;
		pq.pop();

		if (hereDist > dist[here]) continue;

		for (auto i : adj[here])
		{
			int nextDist = i.first + hereDist;
			int next = i.second;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}

	cout << dist[E];
}