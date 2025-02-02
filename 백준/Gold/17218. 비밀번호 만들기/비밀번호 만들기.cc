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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;
    str1.insert(str1.begin(), ' ');
    str2.insert(str2.begin(), ' ');

    vvi dp(str1.size(), vi(str2.size(), 0));

    for (int i = 1; i < str1.size(); i++)
    {
        for (int j = 1; j < str2.size(); j++)
        {
            if (str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

 /*   for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }*/

    int x = str1.size() - 1;
    int y = str2.size() - 1;
    string ans;
    while (dp[x][y] != 0)
    {
        if (dp[x - 1][y] == dp[x][y]) x--;
        else if (dp[x][y - 1] == dp[x][y]) y--;
        else
        {
            ans.push_back(str1[x]);
            x--;
            y--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}