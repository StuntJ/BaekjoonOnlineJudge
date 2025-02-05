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

    int N, M;
    cin >> N >> M;

    function<void(int,int, vector<int>&)> solve = [&](int here, int m, vector<int>& v)
    {
        if (m == M)
        {
            for (auto i : v) cout << i << ' ';
            cout << '\n';
            return;
        }
        if (here >= N) return;
        
        v.emplace_back(here + 1);
        solve(here + 1, m + 1, v);
        v.pop_back();

        solve(here + 1, m, v);
    };

    vi v;
    solve(0, 0, v);
}