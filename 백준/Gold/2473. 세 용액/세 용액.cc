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

const ll INF = numeric_limits<ll>::max();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vll v(N);
    for (auto& i : v)
        cin >> i;

    sort(v.begin(), v.end());

    ll diff = INF;
    vll ans(3);

    for (int i = 0; i < N; i++)
    {
        ll make = -v[i];
        int j = i + 1;
        int k = N - 1;
        while (j < k)
        {
            ll d = abs(make - (v[j] + v[k]));
            if (diff > d)
            {
                ans[0] = v[i];
                ans[1] = v[j];
                ans[2] = v[k];
                diff = d;
            }

            if (v[j] + v[k] < make) j++;
            else if (v[j] + v[k] > make)  k--;
            else break;
        }
    }
    for (auto i : ans) cout << i << ' ';
}