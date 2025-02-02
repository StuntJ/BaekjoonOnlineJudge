#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int alpha[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(alpha, -1, sizeof(alpha));

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
        if (alpha[str[i] - 'a'] == -1)
            alpha[str[i] - 'a'] = i;

    for (int i = 0; i < 26; i++)
        cout << alpha[i] << ' ';
}