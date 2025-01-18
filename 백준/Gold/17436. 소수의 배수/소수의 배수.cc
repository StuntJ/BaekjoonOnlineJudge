#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll get_Num(ll upper, ll p)
{
	return upper / p;
}

int main()
{
	ll N, M;
	cin >> N >> M;

	vector<ll> prime(N);
	for (int i = 0; i < N; i++)
	{
		cin >> prime[i];
	}

	ll lim = (1LL << N);
	ll total = 0;
	for (ll i = 1; i < lim; i++)
	{
		ll pop = 0;
		ll temp = 0;
		ll div = 1;
		for (ll j = 0; j < N; j++)
		{
			if (i & (1LL << j))
			{
				pop++;
				div *= prime[j];
			}
		}
		temp += get_Num(M, div);
				
		if (pop % 2) total += temp;
		else total -= temp;
	}
	cout << total << '\n';
}