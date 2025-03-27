#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> v1(N, vector<int>(M));
	vector<vector<int>> v2(N, vector<int>(M));
	vector<vector<int>> s(N, vector<int>(M));
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> v1[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> v2[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			s[i][j] = v1[i][j] + v2[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << s[i][j] << ' ';
		}
		cout << '\n';
	}
}