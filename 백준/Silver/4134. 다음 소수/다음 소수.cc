#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isPrime(ll n)
{
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
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
		if (N <= 2)
		{
			cout << 2 << '\n';
			continue;
		}

		while (!isPrime(N))
			N += 1;

		cout << N << '\n';
	}


}