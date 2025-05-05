#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	typedef long long ll;

	int N, Q;
	cin >> N >> Q;

	vector<ll> v(N);
	for (auto& i : v) cin >> i;
	v.insert(v.begin(), 0);
	vector<ll> pSum(N + 1);
	vector<ll> pS(N + 1);
	for (int i = 1; i <= N; i++) pSum[i] = pSum[i - 1] + v[i];
	for (int i = 1; i <= N; i++) pS[i] = pS[i - 1] + v[i] * pSum[i - 1];

	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		
		if (a == 1) cout << pS[b] << '\n';
		else cout << pS[b] - pS[a - 1] - pSum[a - 1] * (pSum[b] - pSum[a - 1]) << '\n';
	}
}