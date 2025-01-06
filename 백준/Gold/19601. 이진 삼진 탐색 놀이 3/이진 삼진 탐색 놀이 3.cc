#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Q;
	cin >> Q;
	while (Q--)
	{
		ll N;
		cin >> N;

		ll cnt1 = 0;
		ll k = N;
		while (k >= 2)
		{
			k /= 2;
			cnt1++;
		}

		ll cnt2 = 0;
		ll p = N;
		while (p >= 3)
		{
			p /= 3;
			cnt2 += 2;
		}
		if (p == 2) cnt2++;
		cout << cnt1 << ' ' << cnt2 << '\n';

	}
}