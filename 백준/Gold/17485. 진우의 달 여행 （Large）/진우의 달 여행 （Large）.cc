#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, m;
vector <vector<int>> MAP(1002, vector<int>(1002, 0));
vector <vector<vector<int>>> DP(1002, vector< vector<int> >(1002, vector<int>(3, INF)));

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            int tmp; cin >> tmp;
            MAP[i][j] = tmp;

            if (i == 1)
            {
                DP[i][j][0] = MAP[i][j];
                DP[i][j][1] = MAP[i][j];
                DP[i][j][2] = MAP[i][j];
            }
        }
    }

    for (int i = 2; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {

            DP[i][j][0] = min(DP[i - 1][j + 1][1], DP[i - 1][j + 1][2]) + MAP[i][j];
            DP[i][j][1] = min(DP[i - 1][j][0], DP[i - 1][j][2]) + MAP[i][j];
            DP[i][j][2] = min(DP[i - 1][j - 1][0], DP[i - 1][j - 1][1]) + MAP[i][j];
        }
    }
    int answer = INF;
    for (int j = 1; j <= m; j++)
    {
        for (int k = 0; k < 3; k++) 
        {
            if (answer > DP[n][j][k]) 
            {
                answer = DP[n][j][k];
            }
        }
    }

    cout << answer << '\n';

    return 0;
}