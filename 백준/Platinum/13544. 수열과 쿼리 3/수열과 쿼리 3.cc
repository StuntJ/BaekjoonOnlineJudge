#include <bits/stdc++.h>

using namespace std;

typedef int mData;

struct MSQ
{
	int n;
	vector<vector<mData>> rangeMerge;
	
	MSQ(const vector<mData>& array)
	{
		n = array.size();
		rangeMerge.resize(n * 4);
		init(array, 1, 0, n - 1);
	}

	void init(const vector<mData>& array, int node, int nodeLeft, int nodeRight)
	{
		if (nodeLeft == nodeRight) 
		{
			rangeMerge[node].emplace_back(array[nodeLeft]);
			return;
		}
		int mid = (nodeLeft + nodeRight) / 2;
		init(array, node * 2, nodeLeft, mid);
		init(array, node * 2 + 1, mid + 1, nodeRight);
		rangeMerge[node].resize(rangeMerge[node * 2].size() + rangeMerge[node * 2 + 1].size());
		merge(rangeMerge[node * 2].begin(), rangeMerge[node * 2].end(), rangeMerge[node * 2 + 1].begin(), rangeMerge[node * 2 + 1].end(), rangeMerge[node].begin());
	}

	mData query(int left, int right, int k, int node, int nodeLeft, int nodeRight)
	{
		if (nodeRight < left || right < nodeLeft) return 0;
		if (left <= nodeLeft && nodeRight <= right) return rangeMerge[node].size() - (upper_bound(rangeMerge[node].begin(), rangeMerge[node].end(), k) - rangeMerge[node].begin());
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, k, node * 2, nodeLeft, mid) + query(left, right, k, node * 2 + 1, mid + 1, nodeRight);
	}

	int query(int left, int right, int k) //mData의 형식에 맞출 것
	{
		return query(left, right, k, 1, 0, n - 1);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	MSQ seg(v);

	int M;
	cin >> M;

	int prev = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;
		a ^= prev;
		b ^= prev;
		k ^= prev;
		a--;
		b--;

		prev = seg.query(a, b, k);
		cout << prev << '\n';
	}
}