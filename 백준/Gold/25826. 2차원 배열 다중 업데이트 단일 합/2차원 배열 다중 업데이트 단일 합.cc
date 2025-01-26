#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<ll>> B(N, vector<ll>(N));
    vector<vector<ll>> arr(N+1, vector<ll>(N+1,0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    for (int i = 0; i < M; i++)
    {
        int Q;
        cin >> Q;
        if (Q == 1)
        {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            ll k;
            cin >> k;
            arr[i1][j1] += k;
            arr[i2 + 1][j2 + 1] += k;
            arr[i2 + 1][j1] -= k;
            arr[i1][j2 + 1] -= k;
        }
        else
        {
            for (int i = 0; i < N; i++)
                for (int j = 1; j < N; j++)
                    arr[i][j] += arr[i][j - 1];

            for (int i = 0; i < N; i++)
                for (int j = 1; j < N; j++)
                    arr[j][i] += arr[j - 1][i];

            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            ll sum = 0;
            for (int i = i1; i <= i2; i++)
            {
                for (int j = j1; j <= j2; j++)
                {
                    sum += arr[i][j] + B[i][j];
                }
            }
            cout << sum << '\n';
        }
    }
}