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

    while (true)
    {
        string str;
        cin >> str;
        if (str == "0") return 0;

        int N = str.size();
        bool p = true;
        for (int i = 0; i <= (N - 1) / 2; i++)
        {
            if (str[i] != str[N - i - 1]) p = false;
        }
        cout << (p ? "yes\n" : "no\n");
    }
}