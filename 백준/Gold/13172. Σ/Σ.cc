#include <bits/stdc++.h>
#define DIV 1000000007

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
    ll res = temp * temp % DIV;
    if (p & 1) return res * n % DIV;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M;
    cin >> M;

    ll ans = 0;
    for (int i = 0; i < M; i++)
    {
        ll a, b;
        cin >> a >> b;
        
        ans += b * fastPow(a, DIV - 2) % DIV;
        ans %= DIV;
    }
    cout << ans;
}