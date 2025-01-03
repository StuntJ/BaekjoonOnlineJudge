#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct LSQ
{
	int n;
	vector<ll> rangeSum;
	vector<ll> lazy;

	LSQ(const vector<ll>& array)
	{
		n = array.size();
		rangeSum.resize(n * 4);
		lazy.assign(n * 4, 0);
		init(array, 1, 0, n - 1);
	}

	ll init(const vector<ll>& array, int node, int nodeLeft, int nodeRight)
	{
		if (nodeLeft == nodeRight)
		{
			if (nodeLeft == 0) return rangeSum[node] = array[nodeLeft];
			else return rangeSum[node] = array[nodeLeft] - array[nodeLeft - 1];
		}
		int mid = (nodeLeft + nodeRight) / 2;
		ll leftSum = init(array, node * 2, nodeLeft, mid);
		ll rightSum = init(array, node * 2 + 1, mid + 1, nodeRight);
		return rangeSum[node] = leftSum + rightSum;
	}

	void lazyUpdate(int node, int left, int right)
	{
		if (lazy[node] != 0)
		{
			rangeSum[node] += (right - left + 1) * lazy[node];
			if (left != right)
			{
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
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

	long long query(int x)
	{
		return query(0, x, 1, 0, n - 1);
	}

	void update(int left, int right, ll val, int node, int nodeLeft, int nodeRight)
	{
		lazyUpdate(node, nodeLeft, nodeRight);
		if (nodeRight < left || right < nodeLeft) return;
		if (left <= nodeLeft && nodeRight <= right)
		{
			rangeSum[node] += val * (nodeRight - nodeLeft + 1);
			if (nodeLeft != nodeRight)
			{
				lazy[node * 2] += val;
				lazy[node * 2 + 1] += val;
			}
			return;
		}
		int mid = (nodeLeft + nodeRight) / 2;
		update(left, right, val, node * 2, nodeLeft, mid);
		update(left, right, val, node * 2 + 1, mid + 1, nodeRight);
		rangeSum[node] = rangeSum[node * 2] + rangeSum[node * 2 + 1];
	}

	void update(int left, int right, ll val)
	{
		update(left, right, val, 1, 0, n - 1);
		if (right < n - 1) update(right + 1, right + 1, -(right - left + 1), 1, 0, n - 1);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<ll> arr(N);
	for (auto& i : arr) cin >> i;

	LSQ seg(arr);

	int Q;
	cin >> Q;
	while (Q--)
	{
		int qu;
		cin >> qu;
		if (qu == 1)
		{
			int L, R;
			cin >> L >> R;
			seg.update(L - 1, R - 1, 1);
		}
		else
		{
			ll x;
			cin >> x;
			cout << seg.query(x - 1) << '\n';
		}
	}
}