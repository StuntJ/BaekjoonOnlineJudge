#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<ll> A(N), B(N);
	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;

	vector<ll> remain(N);
	for (int i = 0; i < N; i++)
	{
		remain[i] = A[i] / B[i];
		if (A[i] % B[i] != 0) remain[i]++;
	}

	ll s = 0, e = 1000000000;
	ll ans = 1000000000;
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += max(remain[i] - mid, 0LL);
		}
		if (sum > mid)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
			ans = min(ans, mid);
		}
	}
	cout << ans;
}