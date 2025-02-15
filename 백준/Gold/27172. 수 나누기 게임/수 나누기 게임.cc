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
    vi cnt(N);

    unordered_map<int,int> us;
    vi v(N);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        us.insert({ x,i });
        v[i] = x;
    }

    for (auto num : v)
    {
        for (int i = num*2; i <= 1000000; i += num)
        {
            if (us.find(i) != us.end())
            {
                cnt[us[i]]--;
                cnt[us[num]]++;
            }
        }
    }

    for (auto i : cnt) cout << i << ' ';
}