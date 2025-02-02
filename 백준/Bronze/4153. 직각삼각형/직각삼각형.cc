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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        vi v(3);
        for (auto& i : v) cin >> i;
        if (v[0] == 0) return 0;
        sort(v.begin(), v.end());

        cout << ((v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) ? "right\n" : "wrong\n");
    }
}