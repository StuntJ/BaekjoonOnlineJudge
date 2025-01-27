#include <bits/stdc++.h>
#define MAX_N 2510

using namespace std;

int bR[MAX_N][MAX_N];
int bD[MAX_N][MAX_N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int W, H, K;
	cin >> W >> H >> K;

	auto isInrange = [&](int x, int y)
	{
		return 0 <= x && x <= H && 0 <= y && y <= W;
	};
	//입력된 좌표는 전치시키고 +1해서 진행
	for (int i = 0; i < K; i++)
	{
		int Q;
		cin >> Q;
		if (Q == 1)
		{
			int px, py, qx, qy;
			cin >> px >> py >> qx >> qy;
			swap(px, py); swap(qx, qy);
			px++, py++, qx++, qy++;
			bR[px][py] += 1;
			bR[px][qy + 1] -= 1;
			bR[qx + 1][qy + 1] -= 1;
			bR[qx + 1][py] += 1;

		}
		else if (Q == 2)
		{
			int px, py, r;

			cin >> px >> py >> r;
			swap(px, py);
			px++, py++;

			bD[px - r][py] += 1;
			bD[px - r + 1][py] += 1;
			bD[px + r + 1][py] += 1;
			bD[px + r + 2][py] += 1;

			bD[px + 1][py - r - 1] -= 1;
			bD[px + 1][py - r] -= 1;
			bD[px + 1][py + r] -= 1;
			bD[px + 1][py + r + 1] -= 1;

		}
	}
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			bR[i][j] += bR[i][j - 1];

	for (int i = 1; i <= W; i++)
		for (int j = 1; j <= H; j++)
			bR[j][i] += bR[j - 1][i];

	/*for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << bD[i][j] << ' ';
		cout << '\n';
	}cout << '\n';*/

	for (int i = 1; i <= W; i++)
	{
		int x = 1, y = i;
		int dx = 1, dy = -1;
		while (isInrange(x, y))
		{
			bD[x][y] += bD[x - 1][y + 1];
			x += dx;
			y += dy;
		}
	}

	for (int i = 2; i <= H; i++)
	{
		int x = i, y = W;
		int dx = 1, dy = -1;
		while (isInrange(x, y))
		{
			bD[x][y] += bD[x - 1][y + 1];
			x += dx;
			y += dy;
		}
	}

	//for (int i = 1; i <= H; i++)
	//{
	//	for (int j = 1; j <= W; j++)
	//		cout << bD[i][j] << ' ';
	//	cout << '\n';
	//}cout << '\n';

	for (int i = 1; i <= W; i++)
	{
		int x = 1, y = i;
		int dx = 1, dy = 1;
		while (isInrange(x, y))
		{
			bD[x][y] += bD[x - 1][y - 1];
			x += dx;
			y += dy;
		}
		/*for (int p = 1; p <= H; p++)
		{
			for (int q = 1; q <= W; q++)
				cout << bD[p][q] << ' ';
			cout << '\n';
		}cout << '\n';*/
	}

	for (int i = 2; i <= H; i++)
	{
		int x = i, y = 1;
		int dx = 1, dy = 1;
		while (isInrange(x, y))
		{
			bD[x][y] += bD[x - 1][y - 1];
			x += dx;
			y += dy;
		}

	}

	/*for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << bD[i][j] << ' ';
		cout << '\n';
	}cout << '\n';*/

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cout << (((bD[i][j] + bR[i][j]) % 2 == 1) ? '#' : '.');
		}
		cout << '\n';
	}
}