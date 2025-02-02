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

    vvi apart(15, vi(15, 0));
    for (int i = 1; i < 15; i++) apart[0][i] = i;
    for (int i = 1; i < 15; i++)
    {
        for (int j = 1; j < 15; j++)
        {
            apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        cout << apart[n][k] << '\n';
    }
}