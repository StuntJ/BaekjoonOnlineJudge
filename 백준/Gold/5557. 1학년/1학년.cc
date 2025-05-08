#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	typedef long long ll;
	
	vector<vector<ll>> dp(N, vector<ll>(21,-1));
	vector<int> v(N);
	for (auto& i : v) cin >> i;

	auto solve = [&](auto& solve, int n, int val)->ll
	{
		if (n == N - 1)
		{
			if (val == v[N - 1]) return 1;
			else return 0;
		}

		ll& ret = dp[n][val];
		if (ret != -1) return ret;
		ret = 0;

		if (n >= 1 && val - v[n] >= 0)
			ret += solve(solve, n + 1, val - v[n]);
		if (val + v[n] <= 20)
			ret += solve(solve, n + 1, val + v[n]);
		return ret;
	};
	cout << solve(solve, 0, 0);
}