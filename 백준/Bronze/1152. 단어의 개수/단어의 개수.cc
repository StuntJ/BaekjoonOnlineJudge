#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);
    int cnt = 0;
    for (int i=0;i<str.size();i++)
        if (i!=0&&i!=str.size()-1&&str[i] == ' ') cnt++;
    if (str == " ") cout << 0 << '\n';
    else cout << ++cnt;
}