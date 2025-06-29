#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	typedef long long ll;

	int N, M, A, B;
	cin >> N >> M >> A >> B;
	vector<tuple<ll,ll,ll>> R(M);
	vector<vector<ll>> adj(N + 1,vector<ll>(N+1,-1));
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		R[i] = { a,b,c };
		adj[a][b] = c;
		adj[b][a] = c;
	}
	
	const ll INF = 1e15;
	auto dijkstra = [&]()->ll {
		vector<ll> dist(N + 1, INF);
		priority_queue<pair<ll,int>> pq;
		dist[A] = 0;
		pq.push({ 0,A });
		while (!pq.empty()) {
			auto [hereDist, here] = pq.top();
			hereDist = -hereDist;
			pq.pop();
			
			if (hereDist > dist[here]) continue;
			for (int next = 1; next <= N; next++) {
				if (adj[here][next] == -1) continue;
				ll nextDist = hereDist + adj[here][next];
				if (nextDist < dist[next]) {
					dist[next] = nextDist;
					pq.push({ -nextDist,next });
				}
			}
		}
		return dist[B];
	};

	ll ans = dijkstra();
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		for(int j=0;j<M;j++){
			auto [x, y, t] = R[j];
			ll nt;
			cin >> nt;
			adj[x][y] = nt;
			adj[y][x] = nt;
		}
		ans = min(dijkstra(), ans);
	}
	cout << ans;
}