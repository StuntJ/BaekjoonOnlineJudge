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

    ll A, B;
    cin >> A >> B;

    queue<pair<ll,ll>> q;
    map<ll, ll> mp;
    q.push({A,0});
    mp[A]++;
    while (!q.empty())
    {
        pair<ll,ll> here = q.front();
        q.pop();
        if (here.first > B) continue;
        if (here.first == B)
        {
            cout << here.second+1 << '\n';
            return 0;
        }

        ll nx = here.first * 10 + 1;
        if (mp.find(nx) == mp.end())
        {
            mp[nx]++;
            q.push({nx,here.second+1});
        }
        nx = here.first * 2;
        if (mp.find(nx) == mp.end())
        {
            mp[nx]++;
            q.push({ nx,here.second + 1 });
        }
    }
    cout << -1 << '\n';
}