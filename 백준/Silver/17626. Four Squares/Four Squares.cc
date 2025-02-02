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

ll dp[50001];
const ll INF = 1000000000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dp, dp + 50001, INF);
    for (int i = 1; i < 50001; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (j * j == i)
            {
                dp[i] = 1;
                break;
            }
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }

    ll N;
    cin >> N;
    cout << dp[N];
}