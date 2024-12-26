#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(vector<int> &num, int bit)
{
	ll one = 0, zero = 0;
	for (auto x : num)
	{
		if (x & (1 << bit)) one++;
		else zero++;
	}
	return one * zero;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> num(N);
	for (auto& a : num) cin >> a;

	ll ans = 0;
	for (int i = 0; i < 20; i++)
	{
		ans += (1 << i) * solve(num, i);
	}
	cout << ans;
}