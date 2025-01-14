#include <bits/stdc++.h>
#define MAX_N 1000001
using namespace std;

typedef long long ll;
bool chk[MAX_N];

vector<ll> get_prime()
{
	chk[1] = true;

	for (int i = 2; i * i <= MAX_N - 1; i++)
		for (int j = i * i; j <= MAX_N - 1; j += i)
			chk[j] = true;

	vector<ll> prime;
	for (int i = 1; i < MAX_N; i++)
		if (!chk[i])
			prime.emplace_back(i);

	return prime;
}

bool isPrime(ll n)
{
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);



	vector<ll> seg;
	ll N;
	cin >> N;

	ll tot = N;
	for (ll i = 2; i * i <= N; i++)
	{
		if (isPrime(i) && N % i == 0)
		{
			seg.emplace_back(i);
			while (N % i == 0)
				N /= i;
		}
	}
	if (N > 1) seg.emplace_back(N);
	
	for (int i = 0; i < seg.size(); i++)
	{
		tot /= seg[i];
		tot *= (seg[i] - 1);
	}

	cout << tot;
}