#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> A(N);
	int xorRes = 0;
	for (auto& i : A)
	{
		cin >> i;
		xorRes ^= i;
	}

	int ans = xorRes;
	for (auto i : A)
		ans = max(ans, i ^ xorRes);

	cout << ans << ans;
}