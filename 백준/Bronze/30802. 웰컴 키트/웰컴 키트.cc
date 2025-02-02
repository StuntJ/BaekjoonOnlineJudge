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

    int N;
    cin >> N;
    vi v(6);
    for (auto& i : v) cin >> i;
    int T, P;
    cin >> T >> P;
    int tnum = 0;
    for (auto i : v)
    {
        int hereNum = i / T + 1;
        if (i % T==0) hereNum--;
        tnum += hereNum;
    }

    int pnum = N / P;
    int prem = N % P;
    cout << tnum << '\n';
    cout << pnum << ' ' << prem << '\n';
}