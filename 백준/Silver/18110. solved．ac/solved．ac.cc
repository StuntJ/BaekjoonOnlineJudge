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

    int N;
    cin >> N;

    int cut = round(N * 15.0 / 100.0);
    vd v(N);
    for (auto& i : v) cin >> i;
    if (N == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    sort(v.begin(), v.end());
    double sum = 0;
    for (int i = cut; i < N - cut; i++)
    {
        sum += v[i];
    }

    int ans = round(sum / (N - 2 * cut));
    cout << ans;
}