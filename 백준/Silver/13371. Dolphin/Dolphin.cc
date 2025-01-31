#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

		ll n = 0;
		ll s = 0, e = 100000;
		ll nextN = numeric_limits<int>::max();
		while (s <= e)
		{
			ll mid = (s + e) / 2;
			ll res = (3 * mid * mid + 3 * mid) / 2;
			if (res < N)
			{
				n = max(n, mid);
				nextN = min(nextN, N - res);
				s = mid + 1;
			}
			else e = mid - 1;
		}
		n++;
		N = nextN;
		if (N <= n)
			cout << n << (n == 1 ? " dolphin\n" : " dolphins\n");
		else if (N <= 2 * n)
			cout << n << (n == 1 ? " jump\n" : " jumps\n");
		else
			cout << "splash\n";
	}
}