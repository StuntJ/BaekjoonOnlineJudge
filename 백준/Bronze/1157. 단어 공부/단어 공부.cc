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

    vi cnt(26);
    string str;
    cin >> str;
    for (auto& ch : str)
        if (ch > 'Z')
            ch -= 32;

    //cout << str << '\n';

    for (auto ch : str)
        cnt[ch - 'A']++;

   

    int k = *max_element(cnt.begin(), cnt.end());
    int p = 0;
    for (auto i : cnt)
    {
        if (i == k) p++;
    }
    if (p > 1) cout << '?';
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == k) cout << char(i + 'A');
        }
    }
}