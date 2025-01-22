#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int adj[5][5] = {
	1,2,2,2,2,
	INF,1,3,4,3,
	INF,3,1,3,4,
	INF,4,3,1,3,
	INF,3,4,3,1
};

long long dp[5][5][100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 100001; k++)
				dp[i][j][k] = INF;
		
	
	dp[0][0][0] = 0;
	while (true)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		N++;

		for (int i = 0; i < 5; i++)
		{
			if (i == x) continue;
			for (int j = 0; j < 5; j++)
			{
				dp[x][i][N] = min(dp[x][i][N],min(dp[j][i][N - 1] + adj[j][x], dp[x][j][N-1] + adj[j][i]));
			}
			for (int j = 0; j < 5; j++)
			{
				dp[i][x][N] = min(dp[i][x][N],min(dp[j][x][N - 1] + adj[j][i], dp[i][j][N - 1] + adj[j][x]));
			}
		}
		/*for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << dp[i][j][N] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
	}
	long long m = INF;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m = min(m,dp[i][j][N]);
		}
	}

	cout << m;
}