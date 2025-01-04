#include <bits/stdc++.h>
#define DIV 998244353
#define MAX_N 1001
#define MAX_M 101
using namespace std;

typedef long long ll;
ll dp[MAX_N][MAX_M][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= M; i++) dp[1][i][0] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (k < j)
				{
					dp[i][k][0] += dp[i - 1][j][0];
					dp[i][k][0] %= DIV;
				}
				else if (k == j)
				{
					dp[i][k][0] += dp[i - 1][j][0] + dp[i - 1][j][1];
					dp[i][k][0] %= DIV;
				}
				else 
				{
					dp[i][k][1] += dp[i - 1][j][0] + dp[i - 1][j][1];
					dp[i][k][1] %= DIV;
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= M; i++)
	{
		ans += dp[N][i][0] + dp[N][i][1];
		ans %= DIV;
	}
	cout << ans;
}