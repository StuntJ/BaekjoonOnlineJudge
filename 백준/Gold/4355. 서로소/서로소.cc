#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fastPow(ll n, ll p, ll mod)
{
	if (p == 0) return 1;
	ll temp = fastPow(n, p / 2, mod);
	ll ret = temp * temp % mod;
	if (p & 1) return ret * n % mod;
	return ret;
}

ll EulerPi(ll x)
{
	vector<ll> v;
	ll ans = x;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i==0) v.emplace_back(i);
		while (x % i == 0)
		{
			x /= i;
		}
	}
	if (x != 1) v.emplace_back(x);
	
	for (auto i : v)
	{
		ans /= i;
		ans *= (i - 1);
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		ll N;
		cin >> N;

		if (N == 0) return 0;
		if (N <= 1) cout << 0 << '\n';
		else cout << EulerPi(N) << '\n';
	}
	

}