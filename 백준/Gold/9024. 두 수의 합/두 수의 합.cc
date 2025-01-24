#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int INF = numeric_limits<int>::max();
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        sort(v.begin(), v.end());
        int l = 0, r = N - 1;
        int m = INF;
        int cnt = 0;

        while (l < r)
        {
            int sum = v[l] + v[r];
            if (sum == K) l++, r--;
            else if (sum < K) l++;
            else r--;

            int res = abs(K - sum);
            if (m == res) cnt++;
            if (m > res) m = res, cnt = 1;
  
        }
        cout << cnt << '\n';
    }
}