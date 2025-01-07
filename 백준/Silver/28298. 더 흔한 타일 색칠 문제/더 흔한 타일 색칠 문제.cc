#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<char>> board(N,vector<char>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	int alphaNum[26];
	int total = 0;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < K; j++)
		{	
			memset(alphaNum, 0, sizeof(alphaNum));
			int maximum = 0;
			char most;
			for (int x = i; x < N; x += K)
				for (int y = j; y < M; y += K)
				{
					alphaNum[board[x][y]-'A']++;
					if (maximum < alphaNum[board[x][y]-'A'])
					{
						maximum = alphaNum[board[x][y]-'A'];
						most = board[x][y];
					}
				}
			for (int x = i; x < N; x += K)
				for (int y = j; y < M; y += K)
					board[x][y] = most;

			int dx = N / K;
			int dy = M / K;

			int change = dx * dy - maximum;
			//cout << change << '\n';
			total += change;
		}
	}
	cout << total << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << board[i][j];
		cout << '\n';
	}
}


