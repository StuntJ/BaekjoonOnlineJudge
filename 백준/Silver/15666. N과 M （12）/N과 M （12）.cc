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
    vi v(N);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    set<vi> st;

    auto solve = [&](auto& solve, int here, int m, vi& p)
    {
        if(m==M)
        {
            st.insert(p);
            return;
        }
        if (here >= N) return;

        p.push_back(v[here]);
        solve(solve, here, m + 1, p);
        p.pop_back();
        solve(solve, here + 1, m, p);
    };

    vi p;
    solve(solve, 0, 0, p);

    for (auto i : st)
    {
        for (int j = 0; j < M; j++) cout << i[j] << ' ';
        cout << '\n';
    }
}