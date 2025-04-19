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

struct FenwickTree
{
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {} //index 조작을 위해 1~n 을 인덱스로 설정
	int sum(int pos) //구간 합을 구하는 함수 
	{
		pos++; //0~n-1 을 인덱스로 설정했을때 1~n으로 바꾸기 위해 pos++
		int ret = 0;
		while (pos > 0) //더 이상 위로 올라갈 수 없을 때
		{
			ret += tree[pos];
			pos &= (pos - 1); //마지막 비트 제거
		}
		return ret;
	}

	void add(int pos, int val) //pos에 val이 추가됨
	{
		pos++; //0~n-1 을 인덱스로 설정했을때 1~n으로 바꾸기 위해 pos++
		while (pos < tree.size()) //더 이상 위로 올라갈 수 없을 때
		{
			tree[pos] += val; //노드에 val 더하기
			pos += (pos & -pos); //마지막 비트를 계산하여 원래 노드에 그대로 더해주면 다음 노드를 구할 수 있다. 
		}
	}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int T;
	cin >> T;
	int idx = 1;
	while (T--)
	{
		int N, M, K;
		cin >> N >> M >> K;

		FenwickTree seg(M);
		ll sum = 0;
		vvi adj(N);
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;

			adj[a].emplace_back(b);
		}

		for (int i = 0; i < N; i++)
		{
			for (auto j : adj[i])
			{
				sum += seg.sum(M-1)-seg.sum(j);
			}
			for (auto j : adj[i])
				seg.add(j, 1);
		}
		cout <<"Test case "<<idx<<": "<< sum << '\n';
		idx++;
	}
}