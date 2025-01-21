#include <bits/stdc++.h>
#define MAX_N 100001

using namespace std;
typedef long long ll;

int dp[MAX_N];

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
        dp[x] = 1;
    }
    int M;
    cin >> M;
    vector<int> B(M);
    for (auto& i : B) cin >> i;

    for (int i = 1; i < MAX_N; i++)
    {
        for (int j = 2; i * j < MAX_N; j++)
            dp[i * j] += dp[i];
    }

    for (auto i : B) cout << dp[i] << ' ';
    cout << '\n';
}