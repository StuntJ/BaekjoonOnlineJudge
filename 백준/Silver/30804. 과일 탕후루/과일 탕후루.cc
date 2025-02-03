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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vi v(N);
    for (auto& i : v) cin >> i;

    vi cnt(10, 0);
    int num = 0;

    int idx = 0;
    int maxLen = 0;
    for (int i = 0; i < N; i++)
    {
        if (!cnt[v[i]]) num++;
        cnt[v[i]]++;
        while (num > 2)
        {
            if (cnt[v[idx]] == 1) num--;
            cnt[v[idx]]--;
            idx++;
        }
        maxLen = max(maxLen, i - idx + 1);
    }
    cout << maxLen;
}