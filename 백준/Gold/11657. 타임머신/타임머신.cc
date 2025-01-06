#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;

vector<vector<pair<int,ll>>> adj;
int V, E;

vector<ll> SPFA(int src)
{
	vector<ll> dist(V + 1, INF);
	vector<bool> inQ(V + 1, false);
	vector<int> visited(V + 1, 0);
	queue<int> q;
	dist[src] = 0;
	q.push(src);
	inQ[src] = true;
	visited[src]++;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		inQ[here] = false;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			ll cost = adj[here][i].second;

			if (dist[there] > dist[here] + cost)
			{
				dist[there] = dist[here] + cost;
				if (!inQ[there])
				{
					q.push(there);
					inQ[there] = true;
					if (++visited[there] >= V)
						return vector<ll>();
				}
			}
		}
	}
	return dist;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	adj.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		int A, B;
		ll C;
		cin >> A >> B >> C;
		adj[A].emplace_back(make_pair(B, C));
	}

	vector<ll> ans = SPFA(1);
	if (ans.empty())
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= V; i++)
		if (ans[i] == INF) 
			ans[i] = -1;

	for (int i = 2; i <= V; i++)
		cout << ans[i] << '\n';
}