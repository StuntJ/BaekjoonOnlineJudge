#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, M;
	cin >> N >> M;

	ll ans = 0;
	if (N == 1 || N == 5)
	{
		ans += M * 8;
		if (N == 5) ans += 4;
	}
	else
	{
		ans += M / 2 * 8;
		if (M % 2)
		{
			ans += 5;
			ans += 4 - N;
		}
		else
		{
			ans += N - 1;
		}
	}
	cout << ans;
}