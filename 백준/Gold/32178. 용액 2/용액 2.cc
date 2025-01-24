#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<ll,ll>> pSum(N + 1,{0,0});
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		pSum[i].first = pSum[i - 1].first + x;
		pSum[i].second = i;
	}

	sort(pSum.begin(), pSum.end());

	ll ans = numeric_limits<ll>::max();
	ll l, r;
	for (int i = 1; i <= N; i++)
	{
		ll diff = pSum[i].first - pSum[i - 1].first;
		if (diff <= abs(ans))
		{
			l = pSum[i - 1].second;
			r = pSum[i].second;
			if (l > r)
			{
				swap(l, r);
				ans = -diff;
			}
			else ans = diff;
			l++;
		}
	}
	cout << ans << '\n';
	cout << l << ' ' << r;
}