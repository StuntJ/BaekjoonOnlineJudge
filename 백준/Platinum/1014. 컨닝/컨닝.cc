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
		int N, M;
		cin >> N >> M;

		vector<int> P(N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				char x;
				cin >> x;
				if (x == 'x')
					P[i] |= (1 << j);
			}
		}

		vector<vector<int>> cache(N, vector<int>(1 << M, -1));
		auto solve = [&](auto& solve, int idx, int stat)->int
			{
				if (idx == N) return 0;
				int& ret = cache[idx][stat];
				if (ret != -1) return ret;
				ret = 0;

				for (int i = 0; i < (1 << M); i++)
				{
					if (i & P[idx])
						continue;

					bool flag = true;
					for (int j = 0; j < M; j++)
					{
						if (i & (1 << j))
						{
							if (j > 0 && (i & (1 << (j - 1)) || j < M - 1 && (i & (1 << (j + 1)))))
							{
								flag = false;
								break;
							}
							if (j > 0 && (stat & (1 << (j - 1))) || j < M - 1 && (stat & (1 << (j + 1))))
							{
								flag = false;
								break;
							}
						}
					}
					if (flag)
					{
						int cnt = 0;
						for (int j = 0; j < M; j++)
							if (i & (1 << j))
								cnt++;
						ret = max(ret, solve(solve, idx + 1, i) + cnt);
					}
				}

				return ret;
			};

		cout << solve(solve, 0, 0) << '\n';
	}
}