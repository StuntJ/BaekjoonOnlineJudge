#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    int mul = A * B * C;
    string str = to_string(mul);

    for (int i = '0'; i <= '9'; i++)
    {
        int cnt = 0;
        for (auto ch : str)
            if (ch == i)
                cnt++;
        cout << cnt << '\n';
    }
}