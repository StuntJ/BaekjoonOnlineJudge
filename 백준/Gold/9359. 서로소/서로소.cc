#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(ll here, ll A, ll B)
{
	ll a, b;
	if (A % here) a = A / here + 1;
	else a = A / here;
	b = B / here;
	return b - a + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	int cnt = 0;
	while (T--)
	{
		cnt++;
		ll A, B;
		cin >> A >> B;
		ll N;
		cin >> N;

		ll bp = N;
		vector<ll> num;
		for (ll i = 2; i * i <= N; i++)
		{
			if (bp % i == 0)
			{
				num.emplace_back(i);
				while (bp % i == 0)
				{
					bp /= i;
				}
			}
		}
		if (bp > 1) num.emplace_back(bp);

		ll total = 0;
		ll bitMax = (1LL << num.size());

		for (ll i = 1; i < bitMax; i++)
		{
			ll cnt = 0, mul = 1;
			for (ll j = 0; j < num.size(); j++)
			{
				if (i & (1LL << j))
				{
					cnt++;
					mul *= num[j];
				}
			}
			if (cnt & 1) total += solve(mul, A, B);
			else total -= solve(mul, A, B);
		}


		cout << "Case #" << cnt << ": " << B - A + 1 - total << '\n';
	}
}