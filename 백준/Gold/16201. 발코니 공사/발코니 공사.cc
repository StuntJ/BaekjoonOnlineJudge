#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll DIV = 1e+9 + 7;

ll fpow(ll n, ll p) {
	if (p == 0) return 1;
	ll temp = fpow(n, p / 2);
	ll ret = temp * temp % DIV;
	if (p & 1) return ret * n % DIV;
	return ret;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll R, C, Q;
	cin >> R >> C >> Q;
	map<ll, vector<ll>> mp;
	while (Q--) {
		ll a, b;
		cin >> a >> b;

		mp[a].push_back(b);
	}

	ll total = 0;
	ll num = R - mp.size();
	ll ans = fpow(((C & 1) ? (C + 1) / 2 : 1), num);
	total += num * (C / 2);
	ans %= DIV;
	for (auto& vc : mp) {
		sort(vc.second.begin(), vc.second.end());
		ll sz = vc.second.size();
		ll cnt = 1;
		for (int i = 1; i < sz; i++)
		{
			ll size = vc.second[i] - vc.second[i - 1] - 1;
			if (size & 1)
				cnt *= (size + 1)/2;
			cnt %= DIV;
			total += (size) / 2;
		}
		ll size = vc.second[0] - 1;
		if (size & 1)
			cnt *= (size + 1)/2;
		cnt %= DIV;
		total += size / 2;

		size = C - vc.second[sz - 1];
		if (size & 1)
			cnt *= (size+1)/2;
		cnt %= DIV;
		total += size / 2;
		ans *= cnt;
		ans %= DIV;
	}
	cout << total <<' '<< ans;
}