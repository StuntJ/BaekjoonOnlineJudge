#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    unordered_map<int, int> mp;
    for (auto& i : A)
    {
        cin >> i;
        if (i > N)
        {
            cout << 0;
            return 0;
        }
        mp[i]++;
    }

    for (auto& i : A)
    {
        if (mp[i] >= 2)
        {
            mp[i]--;
            while (mp[i] != 0)
            {
                i += K;
            }
            if (i > N)
            {
                cout << 0;
                return 0;
            }

            mp[i]++;
        }
    }

    cout << 1;
}