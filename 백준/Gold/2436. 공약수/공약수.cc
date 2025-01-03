#include <bits/stdc++.h>
#define INF 1000000000000000

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, M;
	cin >> N >> M;

	ll mul = N * M;

	ll ans = INF;
	pair<ll, ll> pi;
	for (ll i = 1; i * i <= mul; i++)
	{
		if (i % N || mul % i || gcd(i, mul / i) != N) continue;
		if (ans > i + mul / i)
		{
			ans = i + mul / i;
			pi = make_pair(i, mul / i);
			//cout << pi.first << ' ' << pi.second << ' ' << ans << '\n';
		}
	}
	cout << pi.first << ' ' << pi.second;
}