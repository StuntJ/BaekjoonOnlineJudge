#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	while (true)
	{
		int N, S, T;
		cin >> N;
		if (N == 0) break;
		cin >> S >> T;

		vector<int> score(N + 2, 0);
		for (int i = 1; i <= N; i++) cin >> score[i];
		vector<vector<int>> dp(N + 2, vector<int>(T + 1, -INF));
		dp[0][0] = 0;
		for (int i = 1; i <= N + 1; i++)
		{
			for (int j = 1; j <= T; j++)
			{
				for (int k = 1; k <= S && i - k >= 0; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + score[i - k]);
				}
			}
		}
		cout << dp[N + 1][T] << '\n';
	}
}