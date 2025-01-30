#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<ll> v(N);
		for (auto& i : v) cin >> i;

		ll M = v[N - 1];
		ll ans = 0;
		for (int i = N - 2; i >= 0; i--)
		{
			M = max(M, v[i]);
			ans += M - v[i];
		}
		cout << ans << '\n';
	}
}