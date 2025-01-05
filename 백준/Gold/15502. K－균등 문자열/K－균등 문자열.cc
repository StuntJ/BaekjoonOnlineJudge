#include <bits/stdc++.h>
#define DIV 1000000007

using namespace std;
typedef long long ll;

struct disjoint_set
{
	vector<int> parent, rank;
	disjoint_set(int n)
	{
		parent.resize(n + 1);
		rank.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (rank[a] > rank[b]) swap(a, b);
		parent[a] = b;
		if (rank[a] == rank[b]) rank[b]++;
	}
};

ll fastPow(ll n, ll p)
{
	if (p == 0) return 1;
	ll temp = fastPow(n, p / 2);
	ll ret = temp * temp % DIV;
	if (p % 2) return ret * n % DIV;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	disjoint_set d_set(N);
	for (int i = 0; i < M; i++)
	{
		int L, R, K;
		cin >> L >> R >> K;
		for (int j = L; j + K <= R; j++)
		{
			d_set.merge(j, j + K);
		}
	}
	vector<bool> chk(N + 1, false);
	ll cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int num = d_set.find(i);
		if (!chk[num])
		{
			cnt++;
			chk[num] = true;
		}
	}
	cout << fastPow(2LL, cnt);
}