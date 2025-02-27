#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fastPow(ll n, ll p)
{
	if (p == 1) return 0;
	ll temp = fastPow(n, p / 2);
	ll ret = temp * temp;
	if (p & 1) return ret * n;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	int rev;
	if (N > 0) rev = 0;
	else N = -N, rev = 1;

	ll lim = (ll)floor(log10(N) / log10(3)) + 1;

	vector<int> comp;

	for (ll i = lim; i >= 0; i--)
	{
		ll bit = pow(3LL, i);
		bool flag = false;
		if (bit < N)
		{
			comp.push_back(1);
			N -= bit;
		}
		else if (bit / 2 < N)
		{
			comp.push_back(1);
			N = bit - N;
			flag = true;
		}
		else if(!comp.empty())
			comp.push_back(0);
		if ((rev & 1)&&!comp.empty()) comp.back() *= -1;
		if (flag) rev++;
	}

	for (auto i : comp)
	{
		if (i == -1) cout << "T";
		else if (i == 1) cout << i;
		else cout << 0;
	}
}