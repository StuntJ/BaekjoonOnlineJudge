#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);

	for (auto& i : v) cin >> i;
	
	sort(v.begin(), v.end());
	if (v.size() <= 2)
	{
		cout << v.size();
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int cnt = 0;
			for (int k = j + 1; k < N; k++)
			{
				if (v[i] + v[j] > v[k]) cnt++;
				else break;
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans+2;
}