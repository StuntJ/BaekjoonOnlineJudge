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

	int x;
	vector<ll> v;
	while(cin>>x)
	{
		v.push_back(x);
	}

	int s = v.size();
	ll M = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			M = max(M, gcd(v[i], v[j]));
		}
	}
	cout << M;
}