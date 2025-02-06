#include <bits/stdc++.h>
#define DIV 1000000007

using namespace std;
typedef long long ll;

ll fastPow(ll n, ll p)
{
	if (p == 0) return 1;
	ll temp = fastPow(n, p / 2);
	ll ret = temp * temp % DIV;
	if (p & 1) return ret * n % DIV;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, a;
	cin >> N >> a;
	
	ll res = N * (N - 1) % DIV;
	res *= (fastPow(N, a) - fastPow(N - 1, a) + DIV) % DIV;
	res %= DIV;
	res += N * fastPow(N - 1, a);
	res %= DIV;
	cout << res << '\n';
}