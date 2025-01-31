#include <bits/stdc++.h>
#define INF 1000000000000000

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, M, K;
	cin >> N >> M >> K;
	vector<ll> orsize(N + 1);
	vector<ll> dp(N + 1, INF);
	dp[0] = 0;

	for (int i = 0; i < N; i++) cin >> orsize[i];

	for (int i = 1; i <= N; i++)
	{
		ll minval = INF;
		ll maxval = 0;
		for (int j = 1; j <= M; j++)
		{
			if (i - j < 0) break;
			minval = min(orsize[i - j], minval);
			maxval = max(orsize[i - j], maxval);
			
			dp[i] = min(dp[i], dp[i - j] + K + (maxval - minval) * j);
		}
	}
	cout << dp[N];
}