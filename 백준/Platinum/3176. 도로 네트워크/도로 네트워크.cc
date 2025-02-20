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

struct dp_data
{
	int dest;
	int mx;
	int mn;
};

const int lim = (int)floor(log2(100000));

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vvpi adj(N + 1);
	vector<vector<dp_data>> dp(lim + 1, vector<dp_data>(N + 1));
	vi depth(N + 1);
	vb visited(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(make_pair(b, c));
		adj[b].emplace_back(make_pair(a, c));
	}

	auto dfs = [&](auto& dfs, int here, int d)->void
		{
			visited[here] = true;
			depth[here] = d;

			for (auto next : adj[here])
			{
				if (visited[next.first]) continue;
				dfs(dfs, next.first, d + 1);
				dp[0][next.first] = { here, next.second, next.second };
			}
		};

	auto makeTable = [&]()
		{
			for (int i = 1; i <= lim; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					dp[i][j].dest = dp[i - 1][dp[i - 1][j].dest].dest;
					dp[i][j].mn = min(dp[i - 1][dp[i - 1][j].dest].mn, dp[i - 1][j].mn);
					dp[i][j].mx = max(dp[i - 1][dp[i - 1][j].dest].mx, dp[i - 1][j].mx);
				}
			}
		};

	auto lca = [&](int a, int b)->pi
		{
			if (depth[a] < depth[b]) swap(a, b);
			int diff = depth[a] - depth[b];
			int mx = 0, mn = 1000001;
			for (int i = 0; diff; i++)
			{
				if (diff & 1)
				{
					mx = max(mx, dp[i][a].mx);
					mn = min(mn, dp[i][a].mn);
					a = dp[i][a].dest;
				}
				diff >>= 1;
			}

			if (a == b) return make_pair(mn, mx);

			for (int i = lim; i >= 0; i--)
			{
				if (dp[i][a].dest != dp[i][b].dest)
				{
					mx = max(mx, dp[i][a].mx);
					mn = min(mn, dp[i][a].mn);
					a = dp[i][a].dest;
					
					mx = max(mx, dp[i][b].mx);
					mn = min(mn, dp[i][b].mn);
					b = dp[i][b].dest;
				}
			}

			mx = max(mx, dp[0][a].mx);
			mx = max(mx, dp[0][b].mx);
			mn = min(mn, dp[0][a].mn);
			mn = min(mn, dp[0][b].mn);
			return make_pair(mn, mx);
		};

	dfs(dfs, 1, 0);
	makeTable();


	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		pi res = lca(a, b);

		cout << res.first << ' ' << res.second << '\n';
	}
}