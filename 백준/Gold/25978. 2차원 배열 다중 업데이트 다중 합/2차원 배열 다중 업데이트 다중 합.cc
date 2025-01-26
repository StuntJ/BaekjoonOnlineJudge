#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<ll>> B(N + 2, vector<ll>(N + 2,0));
	vector<vector<ll>> arr(N + 2, vector<ll>(N + 2,0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> B[i][j];

	bool flag = false;
	for (int i = 0; i < M; i++)
	{
		int Q;
		cin >> Q;
		if (Q == 1)
		{
			int i1, j1, i2, j2;
			ll k;
			cin >> i1 >> j1 >> i2 >> j2 >> k;
			i1++;
			j1++;
			i2++;
			j2++;

			arr[i1][j1] += k;
			arr[i2 + 1][j1] -= k;
			arr[i1][j2 + 1] -= k;
			arr[i2 + 1][j2 + 1] += k;
		}
		else if (Q == 2)
		{
			if (!flag)
			{
				flag = true;
				for (int i = 1; i <= N; i++)
					for (int j = 2; j <= N; j++)
						arr[i][j] += arr[i][j - 1];

				for (int i = 1; i <= N; i++)
					for (int j = 2; j <= N; j++)
						arr[j][i] += arr[j - 1][i];

				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++)
						B[i][j] += arr[i][j];

				
					
				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++)
						B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
			}
			int i1, j1, i2, j2;
			cin >> i1 >> j1 >> i2 >> j2;
			i1++; j1++; i2++; j2++;
			cout << B[i2][j2] - B[i1 - 1][j2] - B[i2][j1 - 1] + B[i1 - 1][j1 - 1] << '\n';
		}
	}
}