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

const ll r = 31;
const ll mod = 1234567891;

ll fastPow(ll n, ll p)
{
    if (p == 0) return 1;
    ll temp = fastPow(n, p / 2);
    ll ret = temp * temp % mod;
    if (p & 1) return ret * n % mod;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);



    int N;
    cin >> N;
    string str;
    cin >> str;

    ll total = 0;
    for (ll i = 0; i < str.size(); i++)
    {
        total += (str[i] - 'a' + 1) * fastPow(r, i) % mod;
        total %= mod;
    }
    cout << total;
}