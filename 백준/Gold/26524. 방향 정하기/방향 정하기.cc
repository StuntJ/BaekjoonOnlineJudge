#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	typedef long long ll;
	const ll DIV = 1000000007;

	int N;
	cin >> N;

	ll prev = 1;
	for (ll i = 1; i <= N; i++)
	{
		prev *= i;
		prev %= DIV;
	}
	cout << prev;
}