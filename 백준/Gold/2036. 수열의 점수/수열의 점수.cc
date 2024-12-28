#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	priority_queue<ll> pqplus;
	priority_queue<ll, vector<ll>, greater<ll>> pqminus;


	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;
		if (x > 0) pqplus.push(x);
		else pqminus.push(x);
	}

	ll ans = 0;
	while (pqplus.size() >= 2)
	{
		ll a = pqplus.top();
		pqplus.pop();
		ll b = pqplus.top();
		pqplus.pop();

		ans += (a + b < a * b) ? a * b : a + b;
	}
	if (pqplus.size())
	{
		ans += pqplus.top();
		pqplus.pop();
	}

	while (pqminus.size() >= 2)
	{
		ll a = pqminus.top();
		pqminus.pop();
		ll b = pqminus.top();
		pqminus.pop();

		ans += a * b;
	}
	if (pqminus.size())
	{
		ans += pqminus.top();
		pqminus.pop();
	}
	cout << ans;
}