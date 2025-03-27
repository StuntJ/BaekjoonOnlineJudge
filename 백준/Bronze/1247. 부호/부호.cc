#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt = 3;
	while (tt--)
	{
		int cnt = 0;
		ll sum = 0;
		int N;
		cin >> N;
		while (N--)
		{
			ll x;
			cin >> x;
			ll prev = sum;
			sum += x;
			if (x > 0 && prev > 0 && sum < 0) cnt++;
			if (x < 0 && prev < 0 && sum > 0) cnt--;
		}
		if (cnt == 0)
		{
			if (sum == 0) cout << 0 << '\n';
			else cout << (sum > 0 ? '+' : '-') << '\n';
		}
		else
			cout << (cnt > 0 ? '+' : '-') << '\n';
	}
}