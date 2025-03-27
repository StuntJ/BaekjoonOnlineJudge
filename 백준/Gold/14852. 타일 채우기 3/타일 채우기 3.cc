#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll DIV = 1000000007;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	vector<ll> dp(N+1);
	dp[0] = 1;
	ll sum = 1;

	for (int i = 1; i <= N; i++)
	{
		int p = i - 1;
		
		dp[i] += sum*2;
		dp[i] %= DIV;
		if (i >= 2) dp[i] += dp[i - 2];
		dp[i] %= DIV;
		sum += dp[i];
		sum %= DIV;
		
	}
	cout << dp[N];
}