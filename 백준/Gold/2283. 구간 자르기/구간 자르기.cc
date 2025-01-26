#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, K;
	cin >> N >> K;

	unordered_map<ll, ll> mp;

	ll st = INF, nd = 0;
	for (int i = 0; i < N; i++)
	{
		ll s, e;
		cin >> s >> e;
		mp[s + 1]++;
		mp[e + 1]--;
		st = min(st, s);
		nd = max(nd, e);
	}

	ll ds = 0; ll de = 0;
	ll s = 0, e = st;
	ll sum = 0;
	for (e; e <= nd; e++)
	{
		while (sum > K && s < e)
		{
			s++;
			ds -= mp[s];
			sum += ds;
		}
		if (sum == K)
		{
			cout << s << ' ' << e << '\n';
			return 0;
		}
		de += mp[e+1];
		sum += de;
	}
	cout << 0 << ' ' << 0 << '\n';
}