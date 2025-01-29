#include <bits/stdc++.h>
#define DIV 1000000007
#define FACT_LIM 101

using namespace std;
typedef long long ll;

ll fact[FACT_LIM];
ll D[FACT_LIM];

void initD()
{
	D[0] = 1;
	D[1] = 0;
	for (int i = 2; i < FACT_LIM; i++)
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % DIV;
}

void initFact()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i < FACT_LIM; i++)
		fact[i] = fact[i - 1] * i % DIV;
}

ll fastPow(ll n, ll p)
{
	if (p == 0) return 1LL;
	ll temp = fastPow(n, p / 2);
	ll ret = temp * temp % DIV;
	if (p & 1LL) return ret * n % DIV;
	return ret;
}

ll bino(ll n, ll r)
{
	ll top = fact[n];
	ll bot = fact[r] * fact[n - r] % DIV;
	bot = fastPow(bot, DIV - 2);
	return top * bot % DIV;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	initFact();
	initD();

	ll N;
	cin >> N;
	ll ans = bino(N, N % 4);
	N -= N % 4;

	ans = ans * D[N] % DIV;
	cout << ans;
}