#include <bits/stdc++.h>

using namespace std;

int R, C, N;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<vector<char>> origin;
vector<vector<char>> rev;
vector<vector<char>> rev2;
vector<vector<char>> full;

void printOrigin()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << origin[i][j];
		cout << '\n';
	}
}

void printRev()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << rev[i][j];
		cout << '\n';
	}
}

void printRev2()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << rev2[i][j];
		cout << '\n';
	}
}

void printFull()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << full[i][j];
		cout << '\n';
	}
}

bool isInrange(int x, int y)
{
	return 0 <= x && x < R && 0 <= y && y < C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> N;

	origin.assign(R, vector<char>(C,'O'));
	rev.assign(R, vector<char>(C,'O'));
	rev2.assign(R, vector<char>(C,'O'));
	full.assign(R, vector<char>(C, 'O'));

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> origin[i][j];
		
	

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (origin[i][j] == 'O')
			{
				rev[i][j] = '.';
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (isInrange(nx, ny))
					{
						rev[nx][ny] = '.';
					}
				}
			}
		}
	}
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (rev[i][j] == 'O')
			{
				rev2[i][j] = '.';
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (isInrange(nx, ny))
					{
						rev2[nx][ny] = '.';
					}
				}
			}
		}
	}

	if (N == 1) printOrigin();
	else if (N % 2 == 0) printFull();
	else if (N % 4 == 3) printRev();
	else printRev2();
}