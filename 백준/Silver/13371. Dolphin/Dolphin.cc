#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cal(ll n)
{
	return (3 * n * n + 3 * n) / 2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		ll N;
		cin >> N;
		ll k = 1;
		while (N > cal(k))
			k++;
		N -= cal(k-1);
		if (N > 2 * k)
		{
			cout << "splash\n";
		}
		else if (N > k)
		{
			cout << k << ' ' << "jump";
			if (k > 2) cout << "s";
			cout << '\n';
		}
		else
		{
			cout << k << ' ' << "dolphin";
			if (k > 1) cout << "s";
			cout << '\n';
		}
	}
}