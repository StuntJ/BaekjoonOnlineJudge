#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fact[21];

void factInit()
{
	fact[0] = fact[1] = 1;
	for (ll i = 2; i <= 20; i++) fact[i] = fact[i - 1] * i;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	factInit();
	int N;
	cin >> N;

	int qu;
	cin >> qu;
	if (qu == 1)
	{
		ll M;
		cin >> M;
		M--;
		vector<bool> chk(N + 1, false);
		for (ll i = N; i > 0; i--)
		{
			ll lim = fact[i] / i;
			ll x = M / lim;
			M -= lim * x;
			for (int j = 1; j <= N; j++)
			{
				if (chk[j]) continue;
				else if (x > 0) x--;
				else
				{
					chk[j] = true;
					cout << j << ' ';
					break;
				}
			}
		}
	}
	else
	{
		vector<int> v(N);
		for (auto& i : v) cin >> i;
		ll ans = 0;
		for (int i = 0; i < N; i++)
		{
			ll mul = fact[N - i] / (N - i);
			ll cnt = 0;
			for (int j = i + 1; j < N; j++)
			{
				if (v[i] > v[j]) cnt++;
			}
			ans += cnt * mul;
		}
		cout << ans+1;
	}
}