#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, K;
	while (cin >> N >> K)
	{
		ll ans = 1;
		for (ll i = 2; i * i <= K; i++)
		{
			ll powK = 0;
			while (K % i == 0)
			{
				K /= i;
				powK++;
			}
			if (powK > 0)
			{
				ll powN = 0;
				for (ll j = i; j <= N; j *= i)
				{
					powN += N / j;
				}
				ll div = pow(i,min(powK, powN));
				ans *= div;
			}
		}
		if (0 < K && K <= N)
			ans *= K;
		cout << ans << '\n';
	}
}