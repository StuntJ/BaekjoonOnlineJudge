#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<ll> v(N);
	for (auto& i : v) cin >> i;
	v.insert(v.begin(), 0);

	vector<pair<ll,ll>> pSum(N + 1,{0,0});
	for (int i = 1; i <= N; i++)
	{
		pSum[i].first = pSum[i - 1].first + v[i];
		pSum[i].second = i;
	}

	sort(pSum.begin(), pSum.end());

	ll ans = numeric_limits<ll>::max();
	ll pr;
	ll l, r;
	for (int i = 1; i <= N; i++)
	{
		ll diff = pSum[i].first - pSum[i - 1].first;
		if (diff <= ans)
		{
			ans = diff;
			l = pSum[i - 1].second;
			r = pSum[i].second;
			if (l > r)
			{
				swap(l, r);
				pr = -ans;
			}
			else pr = ans;
			l++;
		}
	}
	cout << pr << '\n';
	cout << l << ' ' << r;
}