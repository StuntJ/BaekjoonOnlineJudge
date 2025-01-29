#include <bits/stdc++.h>
#define DIV 1000000007

using namespace std;
typedef long long ll;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);
	for (auto& i : v) cin >> i;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (v[i] <= x) cnt++;
	}
	cout << cnt;
}