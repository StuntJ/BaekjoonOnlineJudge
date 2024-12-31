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

	int ans = 0;
	for (int i = 0; i < 20; i++)
	{
		int bit = (1 << i);
		int cnt = 0;
		for(auto k : v)
			if (bit & k) 
				cnt++;
		
		ans = max(ans, cnt);
	}

	cout << ans;
}