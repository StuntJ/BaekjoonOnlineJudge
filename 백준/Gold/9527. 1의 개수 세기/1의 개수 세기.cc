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

ll fastPow(ll n, ll p)
{
    if (p == 0) return 1;
    ll temp = fastPow(n, p / 2);
    ll ret = temp * temp;
    if (p & 1) return ret * n;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll A, B;
    cin >> A >> B;

    auto solve = [&](ll x)
        {
            ll nx = x + 1;
            ll total = 0;
            for (ll i = 0; i <= 60; i++)
            {
                ll div = fastPow(2, i + 1);
                ll sub = fastPow(2, i);

                total += nx / div * sub + max(0LL,(nx % div - sub));
            }
            return total;
        };

    cout << solve(B) - solve(A - 1) << '\n';
}