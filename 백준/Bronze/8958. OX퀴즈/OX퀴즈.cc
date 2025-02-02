#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        int cnt = 0;
        int total = 0;
        for (int i = 0; i < str.size(); i++) (str[i] == 'O') ? total += ++cnt : cnt = 0;

        cout << total << '\n';
    }

}