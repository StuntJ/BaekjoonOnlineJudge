#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct LSQ
{
	int n;
	vector<ll> pSum;
	vector<ll> rangeSum;
	vector<ll> lazy;
	vector<ll> sub;

	LSQ(const vector<ll>& array)
	{
		n = array.size();
		rangeSum.resize(n * 4);
		lazy.assign(n * 4, 0);
		sub.assign(n * 4, 0);
		init(array, 1, 1, n - 1);
	}

	ll init(const vector<ll>& array, int node, int nodeLeft, int nodeRight)
	{
		if (nodeLeft == nodeRight) return rangeSum[node] = array[nodeLeft];
		int mid = (nodeLeft + nodeRight) / 2;
		ll leftSum = init(array, node * 2, nodeLeft, mid);
		ll rightSum = init(array, node * 2 + 1, mid + 1, nodeRight);
		return rangeSum[node] = leftSum + rightSum;
	}

	void lazyUpdate(int node, int left, int right)
	{
		if (lazy[node] != 0)
		{
			ll num = right - left + 1;
			ll a = lazy[node];
			ll d = sub[node];
			rangeSum[node] += num * (2 * a + (num - 1) * d) / 2;

			if (left != right)
			{
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node] + ((left + right) / 2 - left + 1) * sub[node];
				sub[node * 2] += sub[node];
				sub[node * 2 + 1] += sub[node];
			}
			lazy[node] = sub[node] = 0;
		}
	}

	ll query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		lazyUpdate(node, nodeLeft, nodeRight);
		if (nodeRight < left || right < nodeLeft) return 0;
		if (left <= nodeLeft && nodeRight <= right) return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	}

	long long query(int k)
	{
		return query(k, k, 1, 1, n - 1);
	}

	void update(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		lazyUpdate(node, nodeLeft, nodeRight);
		if (nodeRight < left || right < nodeLeft) return;
		if (left <= nodeLeft && nodeRight <= right)
		{
			ll num = nodeRight - nodeLeft + 1;
			ll a = nodeLeft - left + 1;
			ll d = 1;
			rangeSum[node] += num * (2 * a + (num - 1) * d) / 2;
			if (nodeLeft != nodeRight)
			{
				lazy[node * 2] += a;
				lazy[node * 2 + 1] += a + (nodeLeft + nodeRight) / 2 - nodeLeft + 1;
				sub[node * 2]++;
				sub[node * 2 + 1]++;
			}
			return;
		}
		int mid = (nodeLeft + nodeRight) / 2;
		update(left, right, node * 2, nodeLeft, mid);
		update(left, right, node * 2 + 1, mid + 1, nodeRight);
		rangeSum[node] = rangeSum[node * 2] + rangeSum[node * 2 + 1];
	}

	void update(int left, int right)
	{
		update(left, right, 1, 1, n - 1);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<ll> v(N+1);

	for (int i = 1; i <= N; i++) cin >> v[i];

	LSQ seg(v);

	int Q;
	cin >> Q;
	while (Q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int l, r;
			cin >> l >> r;
			seg.update(l, r);
		}
		else
		{
			int k;
			cin >> k;
			cout << seg.query(k) << '\n';
		}
	}
}