#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
const ll DIV = 1000000007;

ll pow(ll n, ll p, ll mod=DIV)
{
	if (p == 1) return n;
	ll temp = pow(n, p / 2, mod);
	ll ret = (temp % mod * temp % mod)%mod;
	if (p & 1) return (ret % mod * n % mod)%mod;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll A;
	ll X;
	cin >> A >> X;

	cout << pow(A%DIV, X);

}