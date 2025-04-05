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

    vi v(3);
    for (auto& i : v) cin >> i;

    int arr[7] = { 0, };
    int p = 0;
    int t = 0;
    for (auto i : v)
    {
        arr[i]++;
        if (arr[i] == 2) p = i;
        if (arr[i] == 3) t = i;
    }

    int k = *max_element(arr, arr + 7);
    if (k == 1) cout << 100 * (*max_element(v.begin(), v.end()));
    else if (k == 2) cout << 1000 + (p * 100);
    else cout << 10000 + (t * 1000);
}