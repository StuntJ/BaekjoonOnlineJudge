#include <bits/stdc++.h>

using namespace std;

struct v_data
{
	int h;
	int s;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, N;
	cin >> H >> N;

	vector<int> dp(H + 1, 0);
	vector<v_data> v(N);
	for (int i = 0; i < N; i++) cin >> v[i].h >> v[i].s;
	v.insert(v.begin(), { 0,0 });

	for (int i = 1; i <= N; i++)
	{
		for (int j = H; j >=0 ; j--)
		{
			int res = dp[j];
			if (j - v[i].h >= 0)
			{
				if (dp[j - v[i].h] == 0 && j - v[i].h == 0) res = max(res, v[i].s);
				else res = max(res, min(dp[j - v[i].h], v[i].s));
			}
			dp[j] = res;
		}
	}
	cout << dp[H];
}