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

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vi v(N);
        for (auto& i : v) cin >> i;

        priority_queue<int> left;
        priority_queue<int, vi, greater<int>> right;
        
        vector<int> res;
        for (int i = 0; i < N; i++)
        {
            if (right.empty() || right.top() >= v[i]) left.push(v[i]);        
            else right.push(v[i]);

            if (i & 1) continue;
            if (left.size() > right.size())
            {
                while (left.size() != right.size() + 1)
                {
                    right.push(left.top());
                    left.pop();
                }
            }
            else
            {
                while (left.size() != right.size() + 1)
                {
                    left.push(right.top());
                    right.pop();
                }
            }
            res.push_back(left.top());
        }
        cout << res.size() << '\n';
        for (auto i : res) cout << i << ' ';
        cout << '\n';
    }
}