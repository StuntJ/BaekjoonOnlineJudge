#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct e_data
{
	int next;
	int dist;
	int cost;
};

struct pq_data
{
	int here;
	int dist;
	int cost;
	bool operator < (const pq_data& rhs) const
	{
		return cost > rhs.cost;
	}
};

vector<vector<e_data>> adj;
vector<vector<int>> dp;

int K, V, E;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> V >> E;

	const int st = 1;
	const int nd = V;
	adj.resize(V + 1);
	dp.assign(V + 1, vector<int>(K + 1, INF));

	for (int i = 0; i < E; i++)
	{
		int s, d, l, t;
		cin >> s >> d >> l >> t;
		e_data dat = { d,l,t };
		adj[s].emplace_back(dat);
	}

	priority_queue<pq_data> pq;
	pq.push({ st,0,K });

	while (!pq.empty())
	{
		pq_data here = pq.top(); pq.pop();
		if (here.dist > dp[here.here][here.cost]) continue;

		for (auto next : adj[here.here])
		{
			int nextCost = here.cost - next.cost;
			if (nextCost < 0) continue;
			int nextDist = here.dist + next.dist;

			if (nextDist < dp[next.next][nextCost])
			{
				pq.push({ next.next,nextDist,nextCost });
				for (int i = nextCost; i>=0; i--)
				{
					if (dp[next.next][i] <= nextDist) break;
					dp[next.next][i] = nextDist;
				}
			}
		}
	}
	int ans = *min_element(dp[nd].begin(), dp[nd].end());
	if (ans == INF) cout << -1;
	else cout << ans;
}