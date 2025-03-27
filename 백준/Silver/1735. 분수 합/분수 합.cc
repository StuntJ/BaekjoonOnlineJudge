#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	ll bot = y1* y2;
	ll top = x1 * y2 + x2 * y1;

	ll g = gcd(bot, top);
	bot /= g;
	top /= g;
	cout << top << ' ' << bot << '\n';
}