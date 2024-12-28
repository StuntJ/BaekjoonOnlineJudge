#include <bits/stdc++.h>
#define MAX_N 1001
#define DIV 1000000003

using namespace std;

typedef long long ll;
ll dp[MAX_N][MAX_N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j];
			dp[i][j] %= DIV;
		}
	}

	ll ans = dp[N - 3][K - 1] + dp[N - 1][K];
	cout << ans % DIV;
}