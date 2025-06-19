#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll DIV = 1e+9 + 7;

ll fpow(ll n, ll p) {
	if (p == 0) return 1;
	ll temp = fpow(n, p / 2);
	ll ret = temp * temp % DIV;
	if (p & 1) return ret * n % DIV;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, K;
	cin >> N >> K;

	ll a = N;
	ll b = N - 1;
	const ll modinv2 = fpow(2, DIV - 2);
	for (int i = 0; i < K; i++) {
		ll na = (a * b)%DIV * modinv2;
		na %= DIV;
		ll nb = 2 * (b - 1);
		nb %= DIV;
		a = na;
		b = nb;
	}

	cout << a;
	//cout << DIV;
}