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
     
    vpi v(N);
    for (auto& i : v) cin >> i.first >> i.second;
    for (auto& i : v)
        if (i.first > i.second)
            swap(i.first, i.second);

    int d;
    cin >> d;

    sort(v.begin(), v.end(), [](pi& a, pi& b)
        {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

    priority_queue<int, vi, greater<int>> pq;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i].second - d <= v[i].first)
            pq.push(v[i].first);
        

        while (!pq.empty()&&pq.top() < v[i].second - d)
            pq.pop();
        ans = max(ans, (int)pq.size());
    }
    cout << ans << '\n';
}