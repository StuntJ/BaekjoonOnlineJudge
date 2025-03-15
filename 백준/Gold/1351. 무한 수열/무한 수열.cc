#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, P, Q;
	cin >> N >> P >> Q;

	unordered_map<ll, ll> mp;

	auto solve = [&](auto& solve, ll here)->ll
		{
			if (mp.find(here) != mp.end()) return mp[here];
			ll ret = solve(solve, here / P) + solve(solve, here / Q);
			mp[here] = ret;
			return ret;
		};

	mp[0] = 1;
	if (N == 0)
	{
		cout << 1;
		return 0;
	}
	
	cout << solve(solve, N / P) + solve(solve, N / Q);
}