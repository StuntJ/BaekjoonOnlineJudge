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

	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		R[i] = { a,b,c };
	}

	int K;
	cin >> K;
	vector<vector<vector<ll>>> adj(K + 1, vector<vector<ll>>(N + 1, vector<ll>(N + 1,-1)));
	for (int i = 0; i < M; i++) {
		auto [x, y, t] = R[i];
		adj[0][x][y] = t;
		adj[0][y][x] = t;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < M; j++) {
			auto [x, y, t] = R[j];
			ll nt;
			cin >> nt;
			adj[i][x][y] = nt;
			adj[i][y][x] = nt;
		}
	}

	const ll INF = 1e15;
	auto dijkstra = [&]()->ll {
		vector<vector<ll>> dist(K+1,vector<ll>(N+1,INF));
		priority_queue<tuple<ll,int,int>> pq;
		dist[0][A] = 0;
		pq.push({ 0,A,0 });
		while (!pq.empty()) {
			auto [hereDist, here, hidx] = pq.top();
			hereDist = -hereDist;
			pq.pop();
			
			if (hereDist > dist[hidx][here]) continue;
			for (int next = 1; next <= N; next++) {
				if (adj[hidx][here][next] == -1) continue;
				ll nextDist = hereDist + adj[hidx][here][next];
				if (nextDist < dist[hidx][next]) {
					dist[hidx][next] = nextDist;
					pq.push({ -nextDist,next,hidx });
				}
			}

			for (int i = hidx+1; i <= K; i++) {
				if(dist[i][here]>hereDist){
					dist[i][here] = hereDist;
					pq.push({ -hereDist,here,i });
				}
			}
		}
		ll ret = INF;
		for (int i = 0; i <= K; i++) ret = min(ret, dist[i][B]);
		return ret;
	};

	ll ans = INF;
	
	ans = min(dijkstra(), ans);
	cout << ans;
}