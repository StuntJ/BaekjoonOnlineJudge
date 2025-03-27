#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int AD = 100000;
const int MAX_N = 200001;

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
	while (T--)
	{
		int N, M;
		cin >> N >> M;

		FenwickTree tree(M + N);
		vector<int> v(N);
		for (int i = M; i < M + N; i++)
		{
			tree.add(i, 1);
			v[i - M] = i;
		}

		for (int i = M-1; i >=0; i--)
		{
			int x;
			cin >> x;
			tree.add(v[--x], -1);
			cout << tree.sum(v[x]) << ' ';
			v[x] = i;
			tree.add(v[x], 1);
		}
		cout << '\n';
	}
}