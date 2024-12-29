#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int x, y;
	cin >> N >> x >> y;
	vector<vector<int>> board(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	int std = board[x][y];
	bool flag = false;
	for (int i = 1; i <=N; i++)
	{
		if (board[x][i] > std)
		{
			flag = true;
			break;
		}
		if (board[i][y] > std)
		{
			flag = true;
			break;
		}
	}
	if (flag) cout << "ANGRY";
	else cout << "HAPPY";

}