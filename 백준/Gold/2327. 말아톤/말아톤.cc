#include <bits/stdc++.h>

using namespace std;

struct v_data
{
	int h;
	int s;

	bool operator < (const v_data& rhs) const
	{
		if (s == rhs.s) return h > rhs.h;
		return s > rhs.s;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, N;
	cin >> H >> N;

	vector<int> dp(H + 1, false);
	vector<v_data> v(N);
	for (int i = 0; i < N; i++) cin >> v[i].h >> v[i].s;
	sort(v.begin(), v.end());
	v.insert(v.begin(), { 0,0 });
	dp[0] = true;

	for (int i = 1; i <= N; i++)
	{
		for (int j = H; j >=v[i].h ; j--)
		{
			dp[j] = max(dp[j], dp[j - v[i].h]);
		}
		if (dp[H])
		{
			cout << v[i].s;
			return 0;
		}
	}
}