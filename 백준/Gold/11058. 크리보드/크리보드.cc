#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	typedef long long ll;

	vector<ll> v(N+1);

	for (int i = 1; i <= N; i++)
	{
		if (i >= 1) v[i] = max(v[i], v[i - 1] + 1);
		for (int j = 3; j < i; j++)
			v[i] = max(v[i], v[i - j] * (j - 1));
	}
	cout << v[N];
}