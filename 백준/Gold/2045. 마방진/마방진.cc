#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int>> v(3, vector<int>(3));

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> v[i][j];

	auto print = [&]()
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					cout << v[i][j] << ' ';
				cout << '\n';
			}
		};

	if (v[0][0] == 0 && v[1][1] == 0 && v[2][2] == 0)
	{
		for (int i = 1; i <= 20000; i++)
		{
			v[0][0] = i;
			int stand = v[0][0] + v[0][1] + v[0][2];
			v[1][1] = stand - v[1][0] - v[1][2];
			v[2][2] = stand - v[2][0] - v[2][1];

			if (v[0][0] + v[1][1] + v[2][2] == stand)
			{
				print();
				return 0;
			}
		}
	}

	if (v[0][2] == 0 && v[1][1] == 0 && v[2][0] == 0)
	{
		for (int i = 1; i <= 20000; i++)
		{
			v[0][2] = i;
			int stand = v[0][0] + v[0][1] + v[0][2];
			v[1][1] = stand - v[1][0] - v[1][2];
			v[2][0] = stand - v[2][1] - v[2][2];

			if (v[0][2] + v[1][1] + v[2][0] == stand)
			{
				print();
				return 0;
			}
		}
	}

	int stand = 0;
	for (int i = 0; i < 3; i++)
	{
		bool flag = true;
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			if (v[i][j] == 0) flag = false;
			sum += v[i][j];
		}
		if (flag) stand = sum;
	}

	for (int i = 0; i < 3; i++)
	{
		bool flag = true;
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			if (v[j][i] == 0) flag = false;
			sum += v[j][i];
		}
		if (flag) stand = sum;
	}

	if (v[0][0] && v[1][1] && v[2][2]) stand = v[0][0] + v[1][1] + v[2][2];
	if (v[0][2] && v[1][1] && v[2][0]) stand = v[0][2] + v[1][1] + v[2][0];

	queue<pair<int, int>> q;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!v[i][j]) q.push({ i,j });


	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		int sum = 0;
		bool flag = true;
		for (int j = 0; j < 3; j++)
		{
			if (j == p.second) continue;
			sum += v[p.first][j];
			if (!v[p.first][j]) flag = false;
		}
		if (flag)
		{
			v[p.first][p.second] = stand - sum;
			continue;
		}

		flag = true;
		sum = 0;
		for (int j = 0; j < 3; j++)
		{
			if (j == p.first) continue;
			sum += v[j][p.second];
			if (!v[j][p.second]) flag = false;
		}
		if (flag)
		{
			v[p.first][p.second] = stand - sum;
			continue;
		}

		if ((p.first + p.second) & 1)
		{
			q.push(p);
			continue;
		}

		flag = true;
		sum = 0;
		for (int j = 0; j < 3; j++)
		{
			if (p.first == j && p.second == j) continue;
			sum += v[j][j];
			if (!v[j][j]) flag = false;
		}
		if (flag)
		{
			v[p.first][p.second] = stand - sum;
			continue;
		}

		flag = true;
		sum = 0;
		for (int j = 0; j < 3; j++)
		{
			if (p.first == j && p.second == 2 - j) continue;
			sum += v[j][2 - j];
			if (!v[j][2 - j]) flag = false;
		}
		if (flag)
		{
			v[p.first][p.second] = stand - sum;
			continue;
		}
		q.push(p);
	}

	print();
}
