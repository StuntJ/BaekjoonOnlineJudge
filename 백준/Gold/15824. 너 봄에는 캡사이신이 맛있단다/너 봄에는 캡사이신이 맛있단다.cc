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

    const int LIM = 300001;
    const ll DIV = 1000000007;

    vll pow2(LIM);
    pow2[0] = 1LL;
    for (int i = 1; i < LIM; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= DIV;
    }
    
    int N;
    cin >> N;

    vll v(N);
    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ll temp = (pow2[i] - pow2[N - i - 1] + DIV) % DIV;
        temp *= v[i];
        temp %= DIV;
        ans += temp;
        ans %= DIV;
    }
    cout << ans;
}