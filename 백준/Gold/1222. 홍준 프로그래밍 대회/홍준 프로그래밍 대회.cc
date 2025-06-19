#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	const int lim = 2 * 1e+6;
	vector<int> v(lim + 1);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v[x]++;
	}

	typedef long long ll;
	ll ans = 0;
	for (int i = 1; i <= lim; i++) {
		ll cnt = 0;
		for (int j = i; j <= lim; j += i) {
			cnt += v[j];
		}
		if(cnt>1) ans = max(ans, cnt * i);
	}
	cout << ans;
}