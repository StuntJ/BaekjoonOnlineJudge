#include <bits/stdc++.h>
#define MAX_N 100001

using namespace std;
typedef long long ll;

int dp[MAX_N];
bool chk[MAX_N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        chk[x] = true;
    }
    int M;
    cin >> M;
    vector<int> B(M);
    for (auto& i : B) cin >> i;

    if (chk[1]) dp[1] = 1;
    else dp[1] = 0;
    for (int i = 2; i < MAX_N; i++)
    {
        if (chk[i]) dp[i]++;
        for (int j = 1; j * j <= i; j++)
        {
            if(i%j==0)
            {
                if (j * j == i) dp[i] += dp[j];
                else
                {
                    dp[i] += dp[j];
                    if (i / j != i) dp[i] += dp[i / j];
                }
            }
        }
    }

    for (auto i : B) cout << dp[i] << ' ';
    cout << '\n';
}