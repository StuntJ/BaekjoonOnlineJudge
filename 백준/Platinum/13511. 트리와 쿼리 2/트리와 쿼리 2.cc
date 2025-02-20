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
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
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

	int N;
	cin >> N;
	const int lim = (int)floor(log2(100000));

	vvpi adj(N + 1);
	vvpll dp(lim + 1, vpll(N + 1));
	vi depth(N + 1);
	vb visited(N + 1);
	vll two(lim + 1);
	for (int i = 0; i <= lim; i++)
	{
		if (i == 0) two[i] = 1;
		else two[i] = two[i - 1] * 2;
	}

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].emplace_back(make_pair(b, c));
		adj[b].emplace_back(make_pair(a, c));
	}

	auto dfs = [&](auto& dfs, int here, int d) ->void
		{
			visited[here] = true;
			depth[here] = d;

			for (auto& next : adj[here])
			{
				if (visited[next.first]) continue;
				dp[0][next.first] = { here,next.second };
				dfs(dfs, next.first, d + 1);
			}
		};

	auto makeTable = [&]()
		{
			for (int i = 1; i <= lim; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					dp[i][j].first = dp[i - 1][dp[i - 1][j].first].first;
					dp[i][j].second = dp[i - 1][dp[i - 1][j].first].second + dp[i - 1][j].second;
				}
			}
		};

	auto lca1 = [&](int a, int b)->ll
		{
			if (depth[a] < depth[b]) swap(a, b);
			int diff = depth[a] - depth[b];
			ll total = 0;
			for (int i = 0; diff; i++)
			{
				if (diff & 1)
				{
					total += dp[i][a].second;
					a = dp[i][a].first;
				}
				diff >>= 1;
			}

			if (a == b) return total;

			for (int i = lim; i >= 0; i--)
			{
				if (dp[i][a].first != dp[i][b].first)
				{
					total += (dp[i][a].second + dp[i][b].second);
					a = dp[i][a].first;
					b = dp[i][b].first;
				}
			}

			total += (dp[0][a].second + dp[0][b].second);
			return total;
		};

	auto lca2 = [&](int a, int b, int k)
		{
			k--;
			bool flag = false;
			if (depth[a] < depth[b]) 
			{
				swap(a, b);
				flag = true;
			}
			int ora = a, orb = b;
			int upa = 0, upb = 0;
			int diff = depth[a] - depth[b];
			for (int i = 0; diff; i++)
			{
				if (diff & 1)
				{
					upa += two[i];
					a = dp[i][a].first;
				}
				diff >>= 1;
			}

			if (a != b)
			{
				for (int i = lim; i >= 0; i--)
				{
					if (dp[i][a].first != dp[i][b].first)
					{
						upa += two[i];
						upb += two[i];
						a = dp[i][a].first;
						b = dp[i][b].first;
					}
				}
				upa++;
				upb++;
			}

			int stn, ndn;
			int stv, ndv;
			if (flag)
			{
				stv = orb, ndv = ora, stn = upb, ndn = upa;
			}
			else
			{
				stv = ora,ndv = orb,stn = upa,ndn = upb;
			}

			if (k <= stn)
			{
				for (int i = 0; k; i++)
				{
					if(k&1) stv = dp[i][stv].first;
					k >>= 1;
				}
				return stv;
			}
			else
			{
				int up = ndn - (k - stn);
				for (int i = 0; up; i++)
				{
					if(up&1) ndv = dp[i][ndv].first;
					up >>= 1;
				}

				return ndv;
			}
		};

	dfs(dfs, 1, 0);
	makeTable();

	int Q;
	cin >> Q;

	while (Q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int a, b;
			cin >> a >> b;
			cout << lca1(a, b) << '\n';
		}
		else if (type == 2)
		{
			int a, b, k;
			cin >> a >> b >> k;
			cout << lca2(a, b, k) << '\n';
		}
	}
}