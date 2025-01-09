#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<ll> v(N);

	for (auto& i : v)
		cin >> i;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	vector<vector<ll>> dp(N, vector<ll>(2));

	for (int i = 0; i < 2; i++)
	{
		if (i == 0) dp[0][i] = 0;
		else dp[0][i] = v[0];
	}

	for (int i = 1; i < N; i++)
	{
		if (i >= 2 && i != N - 1) dp[i][0] = min(dp[i - 2][1], dp[i - 1][1]);
		else dp[i][0] = dp[i - 1][1];
		dp[i][1] = v[i] + dp[i - 1][0];
	}

	ll ret = min(dp[N - 1][0], dp[N - 1][1]);
	//cout << ret << '\n';
	ll ans = accumulate(v.begin(), v.end(), 0LL) - ret;
	cout << ans;
}