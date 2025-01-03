#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FenwickTree
{
	vector<ll> rangeSum, count;
	FenwickTree(ll n)
	{
		rangeSum.resize(n + 1);
		count.resize(n + 1);
	}

	pair<ll, ll> sum(ll pos)
	{
		pos++;
		pair<ll, ll> ret = { 0,0 };
		while (pos > 0)
		{
			ret.first += rangeSum[pos];
			ret.second += count[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void update(ll pos, ll val)
	{
		pos++;
		while (pos < rangeSum.size())
		{
			count[pos] += ((val >= 0) ? 1 : -1);
			rangeSum[pos] += val;
			pos += (pos & -pos);
		}
	}

	void updateTotal(ll left, ll right, ll val)
	{
		update(left, val);
		if (right < rangeSum.size() - 2) update(right + 1, -val);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	ll N;
	cin >> N;
	vector<ll> arr(N);
	for (auto& i : arr) cin >> i;

	FenwickTree seg(N);

	ll Q;
	cin >> Q;

	while (Q--)
	{
		ll qu;
		cin >> qu;
		if (qu == 1)
		{
			ll L, R;
			cin >> L >> R;
			seg.updateTotal(L - 1, R - 1, L);
		}
		else
		{
			ll x;
			cin >> x;
			pair<ll, ll> ans = seg.sum(x - 1);
			//cout << ans.first << ' ' << ans.second << '\n';
			ll res = ans.second * (x + 1) - ans.first + arr[x - 1];
			cout << res << '\n';
		}
	}
}