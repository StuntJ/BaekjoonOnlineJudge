#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int sum = 0;
	cin >> N;
	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) cin >> v[i];
	cin >> M;

	for (int i = N; i > N - M; i--)
		sum += v[i];

	vector<int> dp(N + 1, 0);
	for (int i = 1; i < 4; i++)
	{
		int k = sum;
		for (int j = N; j >= (i * M); j--)
		{
			dp[j] = dp[j - M] + k;
			k -= v[j];
			k += v[j - M];
		}
		for (int j = (i * M) + 1; j <=N ; j++)
			dp[j] = max(dp[j], dp[j - 1]);
	}
	cout << dp[N];
}