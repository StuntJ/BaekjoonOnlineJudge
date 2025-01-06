#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll solve(ll S, ll X)
{
	if (S < X) return 0;
	if ((S - X) & 1) return 0;
	if (X & ((S - X) >> 1)) return 0;
	ll cnt = 0;
	for (ll i = 39; i >= 0; i--)
	{
		ll com = (1LL << i);
		if (X & com) cnt++;
	}
	ll ret = pow(2LL, cnt);
	if (S == X) return ret - 2;
	else return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll S, X;
	cin >> S >> X;
	cout << solve(S, X);
}