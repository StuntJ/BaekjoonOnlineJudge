#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll H;
	cin >> H;

	int N, Q;
	cin >> N >> Q;

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll sum = 0;
	vector<ll> v;
	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;
		v.emplace_back(x);
	}

	sort(v.begin(), v.end(), greater<ll>());
	for (int i = 0; i < N; i++)
	{
		if (sum < H)
		{
			sum += v[i];
			pq.push(v[i]);
		}
		else break;
	}

	if (sum >= H) cout << pq.size() << '\n';
	else cout << -1 << '\n';

	for (int i = 0; i < Q; i++)
	{
		int x;
		cin >> x;
		sum += x;
		pq.push(x);

		while (sum - pq.top() >= H)
		{
			sum -= pq.top();
			pq.pop();
		}
		if (sum >= H) cout << pq.size() << '\n';
		else cout << -1 << '\n';
	}
}