#include <bits/stdc++.h>
#define INF 1000000007

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		ll K, N;
		cin >> K >> N;

		vector<vector<ll>> v(4, vector<ll>(N));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < N; j++)	
				cin >> v[i][j];
			
		vector<ll> fi, se;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)	
				fi.emplace_back(v[0][i] + v[1][j]);
			
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				se.emplace_back(v[2][i] + v[3][j]);

		sort(se.begin(), se.end(), greater<ll>());

		ll sol = INF;
		for (int i = 0; i < fi.size(); i++)
		{
			ll left = K - fi[i];
			auto res = lower_bound(se.begin(), se.end(), left, greater<ll>());
			if (res == se.end())
			{
				int idx = res - se.begin() - 1;
				if (abs(K - se[idx] - fi[i]) < abs(K - sol)) sol = se[idx] + fi[i];
				continue;
			}
			ll p = *res;
			int idx = res - se.begin() - 1;
			ll lower = fi[i] + p;
			ll ans;
			if (idx >= 0)
			{
				ll upper = fi[i] + se[idx];
				if (abs(K - upper) < abs(K - lower))
					ans = upper;
				else
					ans = lower;
			}
			else ans = lower;
			
			if (abs(K - sol) > abs(K - ans))
			{
				sol = ans;
			}
			else if (abs(K - sol) == abs(K - ans))
			{
				if (sol > ans) sol = ans;
			}
		}
		cout << sol << '\n';
	}
}