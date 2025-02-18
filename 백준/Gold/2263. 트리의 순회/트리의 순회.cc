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
    vi in(N), post(N), rev(N + 1);
    for (auto& i : in) cin >> i;
    for (auto& i : post) cin >> i;

    for (int i = 0; i < N; i++)
        rev[in[i]] = i;
    
    vi ans;

    auto solve = [&](auto& solve, int l, int r, int prev = 0)->void
        {
            if (l > r) return;
            if (l == r) 
            {
                ans.push_back(post[l]);
                return;
            }
            solve(solve, r, r, prev);
            int left = rev[post[r]] - (l + prev);
            int right = (r + prev) - rev[post[r]];
            solve(solve, l, l + left - 1, prev);
            solve(solve, r - right, r - 1, prev + 1);
        };
    solve(solve,0,post.size()-1);
    for (auto i : ans) cout << i << ' ';
}