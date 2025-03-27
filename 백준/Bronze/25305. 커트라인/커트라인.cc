#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, k;
	cin >> N >> k;
	vector<int> v(N);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());

	cout << v[N - k];
}