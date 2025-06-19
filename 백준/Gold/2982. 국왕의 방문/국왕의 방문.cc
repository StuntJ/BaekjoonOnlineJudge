#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> fb(N + 1, vector<pair<int, int>>(N + 1));
	vector<vector<int>> adj(N + 1, vector<int>(N + 1));
	int A, B, K, G;
	cin >> A >> B >> K >> G;

	vector<int> path(G);
	for (auto& i : path) cin >> i;
	
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;
	}

	int t = 0;
	for (int i = 0; i < G - 1; i++) {
		fb[path[i]][path[i + 1]] = { t, t + adj[path[i]][path[i + 1]] };
		fb[path[i + 1]][path[i]] = { t, t + adj[path[i]][path[i + 1]] };
		t += adj[path[i]][path[i + 1]];
	}
	
	priority_queue<pair<int, int>> pq;
	const int INF = 1e+9;
	vector<int> dist(N + 1,INF);
	pq.push({ -K, A });
	dist[A] = K;

	while (!pq.empty()) {
		int here = pq.top().second;
		int hereDist = -pq.top().first;
		pq.pop();

		if (dist[here] < hereDist) continue;

		for (int next = 1; next <= N; next++) {
			if (!adj[here][next]) continue;
			int st = fb[here][next].first;
			int nd = fb[here][next].second;
			int nextDist = hereDist + adj[here][next];
			//cout << here << ' ' << hereDist << ' ' << next << ' ' << nextDist << ' ' << st << ' ' << nd << '\n';
			if (st <= hereDist && hereDist < nd) {
				nextDist = nd + adj[here][next];
			}
			
			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}
	}

	cout << dist[B] - K;
}