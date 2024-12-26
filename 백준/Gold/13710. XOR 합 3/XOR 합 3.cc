#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> pXor(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;

		pXor[i] = pXor[i - 1] ^ x;
	}

	ll ans = 0;
	for (int i = 0; i < 30; i++)
	{
		ll mul = (1 << i);
		ll one = 0, zero = 0;
		for (int j = 0; j <= N; j++)
		{
			if (pXor[j] & mul) one++;
			else zero++;
		}
		ans += mul * one * zero;
	}
	cout << ans;
}