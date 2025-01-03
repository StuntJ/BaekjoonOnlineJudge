#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FenwickTree
{
	vector<ll> tree;
	FenwickTree(ll n) : tree(n + 1) {}
	ll sum(ll pos) 
	{
		pos++;
		ll ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(ll pos, ll val)
	{
		pos++;
		while (pos < tree.size())
		{
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}

	void update(ll left, ll right, ll val)
	{
		add(left, val); //B[L] + val
		if (right < tree.size() - 2) add(right + 1, -val); //B[R+1] - val
	}

};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;
	vector<ll> arr(N);
	for (auto& i : arr) cin >> i;

	FenwickTree seg(N);
	for (ll i = 0; i < N; i++)
		seg.update(i, i, arr[i]);

	ll M;
	cin >> M;
	while (M--)
	{
		int q;
		cin >> q;
		if(q==1)
		{
			int i, j, k;
			cin >> i >> j >> k;
			seg.update(i - 1, j - 1, k);
		}
		else
		{
			int x;
			cin >> x;
			cout << seg.sum(x - 1) << '\n';
		}
	}
}