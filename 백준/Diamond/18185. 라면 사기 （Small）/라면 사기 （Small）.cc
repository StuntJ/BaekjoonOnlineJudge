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

    int N;
    cin >> N;

    vector<int> v(N);

    for (auto& i : v)
        cin >> i;
    
    auto buy1 = [&](int st)
        {
            int mul = v[st];
            v[st] = 0;
            return mul * 3;
        };

    auto buy2 = [&](int st)
        {
            int t = min(v[st], v[st + 1]);
            v[st] -= t;
            v[st + 1] -= t;
            return t * 5;
        };

    auto buy3 = [&](int st)
        {
            int t = min(v[st], min(v[st + 1], v[st + 2]));
            v[st] -= t;
            v[st + 1] -= t;
            v[st + 2] -= t;
            return t * 7;
        };

    int ans = 0;
    for (int i = 0; i < N-2; i++)
    {
        if (v[i + 1] > v[i + 2])
        {
            int diff = v[i + 1] - v[i + 2];
            diff = min(diff, v[i]);
            v[i] -= diff;
            v[i + 1] -= diff;
            ans += diff*5;
            ans+=buy3(i);
            ans+=buy1(i);
        }
        else
        {
            ans+=buy3(i);
            ans+=buy2(i);
            ans+=buy1(i);
        }
    }
    ans+=buy2(N - 2);
    ans+=buy1(N-2);
    ans += buy1(N - 1);
    cout << ans;
}