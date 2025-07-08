#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> vp;
	vector<int> w;
	w.push_back(0);
	vp.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		vp.push_back({ x,y });
		w.push_back(max(0, M - (x + y)));
	}
	vector<vector<int>> adj(N + 1);
	vector<int> dp(N + 1,-1);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j) continue;
			if (vp[i].first <= vp[j].first && vp[i].second <= vp[j].second) {
				adj[i].push_back(j);
			}
		}
	}

	auto dfs = [&](auto& dfs, int here)->int {
		int& ret = dp[here];
		if (ret != -1) return ret;
		ret = w[here];
		for (auto next : adj[here]) {
			ret = max(ret, w[here] + dfs(dfs, next));
		}
		return ret;
	};

	cout << dfs(dfs, 0);
}