#include <bits/stdc++.h>
#define INF 1000000000
#define MAX_N 1000001
using namespace std;
typedef long long ll;

ll arr[MAX_N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, K;
	cin >> N >> K;

	ll st = INF, nd = 0;
	for (int i = 0; i < N; i++)
	{
		ll s, e;
		cin >> s >> e;
		arr[s+1]++;
		arr[e+1]--;
		st = min(st, s);
		nd = max(nd, e);
	}

	for (int i = 1; i < MAX_N; i++)
		arr[i] += arr[i - 1];

	ll ds = 0; ll de = 0;
	ll s = 0, e = st;
	ll sum = 0;
	for (e; e <= nd; e++)
	{
		while (sum > K && s < e)
		{
			s++;
			sum -= arr[s];
		}
		if (sum == K)
		{
			cout << s << ' ' << e << '\n';
			return 0;
		}
		sum += arr[e + 1];
	}
	cout << 0 << ' ' << 0 << '\n';
}