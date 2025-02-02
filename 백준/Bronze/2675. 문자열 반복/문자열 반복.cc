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
        int N;
        cin >> N;
        string str;
        cin >> str;

        for (auto i : str)
            for (int j = 0; j < N; j++)
                cout << i;
        cout << '\n';
    }
}