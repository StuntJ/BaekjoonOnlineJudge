#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(8);
    for (auto& i : v) cin >> i;
    vector<int> a, b;
    for (int i = 1; i <= 8; i++)
    {
        a.push_back(i);
        b.push_back(9 - i);
    }
    if (v == a) cout << "ascending\n";
    else if (v == b) cout << "descending\n";
    else cout << "mixed";
}