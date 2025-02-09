#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
ll fastPow(ll n, ll p)
{
	if (p == 0) return 1;
	ll temp = fastPow(n, p / 2);
	ll ret = temp * temp;
	if (p & 1) return ret * n;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	

	unsigned long long N;
	cin >> N;

	while (N%2==0)
	{
		N /= 2;
	}

	for (int i = 0; i < 64; i++)
	{
		if (fastPow(2LL, i) - 1 == N)
		{
			cout << i;
			return 0;
		}
	}

	cout << 64 << '\n';
}