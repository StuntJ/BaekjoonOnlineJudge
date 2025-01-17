#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	string str;
	cin >> str;

	map<ll, ll> mp;
	ll Sxor = 0, total = 0;
	mp[0] = 1;
	for (ll i = 0; i < N; i++)
	{
		ll push = (islower(str[i]) ? str[i] - 'a' : str[i] - 'A' + 26);
		Sxor ^= (1LL << push);
		total += mp[Sxor];
		for (ll j = 0; j < 52; j++)
		{
			if (mp.find(Sxor ^ (1LL << j)) != mp.end()) total += mp[Sxor ^ (1LL << j)];
		}
		mp[Sxor]++;
	}
	cout << total;
}