#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(true)
	{
		int N;
		cin >> N;
		if (N == -1) return 0;
		vector<int> v;

		for (int i = 1; i * i <= N; i++)
		{
			if (N % i) continue;
			v.push_back(i);
			if (i * i == N) continue;
			v.push_back(N / i);
		}
		sort(v.begin(), v.end());

		int ans = accumulate(v.begin(), v.end()-1, 0);
		if (ans == N)
		{
			cout << N << " = ";
			for (int i = 0; i < v.size()-1; i++)
			{
				if (i != v.size() - 2) cout << v[i] << " + ";
				else cout << v[i];
			}
			cout << '\n';
		}
		else cout << N << " is NOT perfect.\n";
	}
	
}