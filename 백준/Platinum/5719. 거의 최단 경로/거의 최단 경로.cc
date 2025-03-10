#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int INF = 987654321;

	while (true)
	{
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) return 0;

		int S, D;
		cin >> S >> D;

		vvpi adj(N);
		vvb con(N, vb(N));

		for (int i = 0; i < M; i++)
		{
			int U, V, P;
			cin >> U >> V >> P;

			adj[U].emplace_back(make_pair(P, V));
			con[U][V] = true;
		}

		int ans = -1;
		bool first = true;
		vvi parent(N);
		vb visited(N);
		auto dfs = [&](auto& dfs, int here)->void
			{
				//cout << here << ' ';
				visited[here] = true;
				for (auto next : parent[here])
				{
					con[next][here] = false;
					if (!visited[next] && next != S)
						dfs(dfs, next);
				}
			};
		while (true)
		{
			vi dist(N, INF);
			dist[S] = 0;
			priority_queue<pi> pq;

			pq.push({ 0,S });

			while (!pq.empty())
			{
				int here = pq.top().second;
				int hereDist = -pq.top().first;
				pq.pop();

				if (hereDist > dist[here]) continue;

				for (auto i : adj[here])
				{
					int nextDist = hereDist + i.first;
					int next = i.second;

					if (nextDist <= dist[next] && con[here][next])
					{
						if (nextDist != dist[next])
						{
							if (first)
								parent[next].clear();
							dist[next] = nextDist;
							pq.push({ -nextDist,next });
						}

						if (first)
							parent[next].emplace_back(here);
						
					}
				}
			}
			//cout << dist[D] << '\n';
			if (first && parent[D].empty())
			{
				ans = -1;
				break;
			}

			//cout << "erase : ";


			if (first)
				dfs(dfs, D);
			//cout << '\n';

			if (dist[D] != ans && !first)
			{
				ans = dist[D];
				if (ans == INF) ans = -1;
				//cout << "ans : " << ans << '\n';
				break;
			}
			ans = dist[D];
			//cout << "ans : " << ans << '\n';
			first = false;
		}

		cout << ans << '\n';
	}
}