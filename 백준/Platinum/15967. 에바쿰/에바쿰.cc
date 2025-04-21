#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

struct LSQ
{
	int n;
	vector<ll> rangeSum;
	vector<ll> Lazy;

	LSQ(const vector<ll>& array)
	{
		n = array.size(); //int n으로 새로 선언하지 않도록 주의 (디버깅할때 찾기 매우 어렵다...)
		rangeSum.resize(n * 4);
		Lazy.assign(n * 4, 0);
		init(array, 1, 0, n - 1);
	}

	ll init(const vector<ll>& array, int node, int nodeLeft, int nodeRight) //초기화는 일반적인 세그와 같음
	{
		if (nodeLeft == nodeRight) return rangeSum[node] = array[nodeLeft];
		int mid = (nodeLeft + nodeRight) / 2;
		ll leftSum = init(array, node * 2, nodeLeft, mid);
		ll rightSum = init(array, node * 2 + 1, mid + 1, nodeRight);
		return rangeSum[node] = leftSum + rightSum;
	}

	void lazyUpdate(int node, int left, int right) //node의 갱신과 lazy의 전파
	{
		if (Lazy[node] != 0)
		{
			rangeSum[node] += (right - left + 1) * Lazy[node]; //node 갱신
			if (left != right)
			{
				Lazy[node * 2] += Lazy[node]; //lazy의 전파
				Lazy[node * 2 + 1] += Lazy[node]; //lazy의 전파
			}
			Lazy[node] = 0; //lazy[node] 초기화
		}
	}

	ll query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		lazyUpdate(node, nodeLeft, nodeRight); //노드를 갱신하고 lazy를 전파 
		if (nodeRight < left || right < nodeLeft) return 0;
		if (left <= nodeLeft && nodeRight <= right) return rangeSum[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	}

	ll query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}

	void update(int left, int right, ll val, int node, int nodeLeft, int nodeRight) //구간에 +val 업데이트
	{
		lazyUpdate(node, nodeLeft, nodeRight); //노드를 갱신하고 lazy를 전파
		if (nodeRight < left || right < nodeLeft) return; //구간에서 벗어남
		if (left <= nodeLeft && nodeRight <= right) //구간과 일치
		{
			rangeSum[node] += (nodeRight - nodeLeft + 1) * val; //노드 갱신
			if (nodeLeft != nodeRight)
			{
				Lazy[node * 2] += val; //val값을 아래노드 lazy에 전파
				Lazy[node * 2 + 1] += val; //val값을 아래노드 lazy에 전파
			}
			return;
		}
		int mid = (nodeLeft + nodeRight) / 2;
		update(left, right, val, node * 2, nodeLeft, mid);
		update(left, right, val, node * 2 + 1, mid + 1, nodeRight);
		rangeSum[node] = rangeSum[node * 2] + rangeSum[node * 2 + 1]; //구간 합 갱신
	}

	void update(int left, int right, ll val)
	{
		update(left, right, val, 1, 0, n - 1);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, Q1, Q2;
	cin >> N >> Q1 >> Q2;
	vll v(N);
	for (auto& i : v) cin >> i;
	LSQ seg(v);

	for (int i = 0; i < Q1 + Q2; i++)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << seg.query(l, r) << '\n';
		}
		else
		{
			int s, e;
			ll l;
			cin >> s >> e >> l;
			seg.update(--s, --e, l);
		}
	}

}