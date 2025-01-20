#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

struct pq_data
{
	int here;
	int dist;

	bool operator < (const pq_data& rhs) const
	{
		return dist > rhs.dist;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	const int st = 1;
	vector<vector<pair<int, int>>> adj(N + 1);
	vector<int> parent(N + 1);
	adj.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		adj[A].emplace_back(make_pair(B,C));
		adj[B].emplace_back(make_pair(A,C));
	}

	priority_queue<pq_data> pq;
	vector<int> dist(N + 1,INF);
	dist[st] = 0;
	pq.push({ st,0 });
	while (!pq.empty())
	{
		pq_data here = pq.top(); pq.pop();
		if (here.dist > dist[here.here]) continue;
		
		for (auto there : adj[here.here])
		{
			int nextDist = here.dist + there.second;
			if (nextDist < dist[there.first])
			{
				parent[there.first] = here.here;
				dist[there.first] = nextDist;
				pq.push({ there.first,nextDist });
			}
		}
	}

	cout << N - 1 << '\n';
	for (int i = st + 1; i <= N; i++)
		cout << i << ' ' << parent[i] << '\n';
}