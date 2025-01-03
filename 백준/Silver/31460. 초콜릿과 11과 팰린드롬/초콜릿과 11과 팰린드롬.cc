#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		//if (N == 1) cout << 0 << '\n';
		if (N % 2)
		{
			if ((N / 2) % 2 == 1) for (int i = 0; i < N; i++) cout << ((i == N / 2) ? 2 : 1);
			else for(int i=0;i<N;i++) cout << ((i == N / 2) ? 0 : 1);
			cout << '\n';
		}
		else
		{
			for (int i = 0; i < N; i++) cout << 1;
			cout << '\n';
		}

	}
}