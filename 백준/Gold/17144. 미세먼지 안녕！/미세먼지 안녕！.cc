#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C, T;
    cin >> R >> C >> T;

    vvi board(R, vi(C));
    int up = -1, down = -1;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
            {
                if (up == -1) up = i;
                else down = i;
            }
        }
    }

    auto isInrange = [&](int x, int y)
        {
            return 0 <= x && x < R && 0 <= y && y < C;
        };

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    while (T--)
    {
        vvi plus(R, vi(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] != 0 && board[i][j] != -1)
                {
                    int origin = board[i][j];
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (!isInrange(nx, ny)||board[nx][ny]==-1) continue;

                        plus[nx][ny] += origin / 5;
                        plus[i][j] -= origin / 5;
                    }
                }
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
                board[i][j] += plus[i][j];
        }

        /*for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';*/

        //up
        int temp = 0;
        for (int j = 1; j < C; j++)
        {
            int bp = board[up][j];
            board[up][j] = temp;
            temp = bp;
        }

        for (int i = up - 1; i > 0; i--)
        {
            int bp = board[i][C - 1];
            board[i][C - 1] = temp;
            temp = bp;
        }

        for (int j = C - 1; j > 0; j--)
        {
            int bp = board[0][j];
            board[0][j] = temp;
            temp = bp;
        }

        for (int i = 0; i < up; i++)
        {
            int bp = board[i][0];
            board[i][0] = temp;
            temp = bp;
        }

        

        //down
        temp = 0;
        for (int j = 1; j < C; j++)
        {
            int bp = board[down][j];
            board[down][j] = temp;
            temp = bp;
        }

        for (int i = down + 1; i < R-1; i++)
        {
            int bp = board[i][C - 1];
            board[i][C - 1] = temp;
            temp = bp;
        }

        for (int j = C - 1; j > 0; j--)
        {
            int bp = board[R-1][j];
            board[R-1][j] = temp;
            temp = bp;
        }

        for (int i = R-1; i > down; i--)
        {
            int bp = board[i][0];
            board[i][0] = temp;
            temp = bp;
        }

        /*for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';*/
    }

    int total = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] != -1)
                total += board[i][j];
        }
    }
    cout << total << '\n';
}