#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> score(N+1);
	vector<int> dp(N+1, 0);

	for (int i = 1; i <= N; i++) cin >> score[i];
	for (int i = 1; i <= N; i++)
	{
		int M = score[i];
		int m = score[i];
		for (int j = i; j >=1 ; j--)
		{
			M = max(M, score[j]);
			m = min(m, score[j]);

			dp[i] = max(dp[i], dp[j - 1] + M - m);
		}
	}

	cout << dp[N];
}