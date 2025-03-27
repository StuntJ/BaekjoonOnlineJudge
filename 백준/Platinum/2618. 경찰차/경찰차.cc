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

	int N, W;
	cin >> N >> W;

	vpi v(W + 1);
	for (int i = 1; i <= W; i++)
		cin >> v[i].first >> v[i].second;

	vvi dp(W + 1, vi(W + 1, -1));

	auto getDist = [&](pi a, pi b)
		{
			return abs(a.first - b.first) + abs(a.second - b.second);
		};

	auto solve = [&](auto& solve, int x, int y)->int
		{
			if (x == W || y == W) return 0;
			int& ret = dp[x][y];
			if (ret != -1) return ret;

			int next = max(x, y) + 1;
			int dist1, dist2;
			if (x == 0) dist1 = getDist(make_pair(1, 1), v[next]);
			else dist1 = getDist(v[x], v[next]); //x->next
			if (y == 0) dist2 = getDist(make_pair(N, N), v[next]);
			else dist2 = getDist(v[y], v[next]); //y->next

			ret = min(dist1 + solve(solve, next, y), dist2 + solve(solve, x, next));
			return ret;
		};

	cout << solve(solve, 0, 0) << '\n';

	auto track = [&](auto& track, int x, int y)->void
		{
			if (x == W || y == W) return;

			int next = max(x, y) + 1;
			int dist1, dist2;
			if (x == 0) dist1 = getDist(make_pair(1, 1), v[next]);
			else dist1 = getDist(v[x], v[next]);
			if (y == 0) dist2 = getDist(make_pair(N, N), v[next]);
			else dist2 = getDist(v[y], v[next]);

			if (dist1 + dp[next][y] < dist2+dp[x][next])
			{
				cout << 1 << '\n';
				track(track, next, y);
			}
			else
			{
				cout << 2 << '\n';
				track(track, x, next);
			}
		};
	track(track, 0, 0);
}