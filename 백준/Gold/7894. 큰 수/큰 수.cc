#include <bits/stdc++.h>
#define MAX_N 10000001
using namespace std;
typedef long long ll;

bool notPrime[MAX_N];

void getPrime(vector<ll> &prime)
{
	notPrime[1] = true;
	for (int i = 2; i * i < MAX_N; i++)
		for (int j = i * i; j < MAX_N; j += i)	
			notPrime[j] = true;
		
	for (int i = 1; i < MAX_N; i++)
		if (!notPrime[i]) prime.emplace_back(i);

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<ll> prime;
	getPrime(prime);

	int N;
	cin >> N;
	while (N--)
	{
		int M;
		cin >> M;
		long double ans = 0;
		for (auto i: prime)
		{
			if (i > M) break;
			ll powM = 0;
			for (ll j = i; j <= M; j *= i)
			{
				powM += M / j;
			}
			//cout << powM << '\n';
			ans += powM * log10(i);
			//cout << ans << '\n';
		}
		ll k = floor(ans) + 1;

		cout << k << '\n';
	}
	
}