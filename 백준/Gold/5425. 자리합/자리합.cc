#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    typedef long long ll;
    int T;
    cin >> T;
    while (T--)
    {
        ll a, b;
        cin >> a >> b;

        auto getDigit = [&](ll n, vector<int> &digit)
        {
            while (n > 0)
            {
                digit.push_back(n % 10);
                n /= 10;
            }
        };

        vector<int> digita, digitb;
        getDigit(a - 1, digita);
        getDigit(b, digitb);

        vector<vector<vector<ll>>> dp(20, vector<vector<ll>>(200, vector<ll>(2, -1)));

        auto solve = [&](auto &solve, int idx, int sum, int tight, vector<int> &digit) -> ll
        {
            if (idx == -1)
                return sum;
            ll &ret = dp[idx][sum][tight];
            if (ret != -1 && tight != 1)
                return ret;
            ret = 0;

            int lim = (tight ? digit[idx] : 9);
            for (int i = 0; i <= lim; i++)
            {
                int newTight = (lim == i ? tight : 0);
                ret += solve(solve, idx - 1, sum + i, newTight, digit);
            }
            return ret;
        };

        ll ansA = solve(solve, digita.size() - 1, 0, 1, digita);

        dp = vector<vector<vector<ll>>>(20, vector<vector<ll>>(200, vector<ll>(2, -1)));
        ll ansB = solve(solve, digitb.size() - 1, 0, 1, digitb);
        cout << ansB - ansA<<'\n';
    }
}