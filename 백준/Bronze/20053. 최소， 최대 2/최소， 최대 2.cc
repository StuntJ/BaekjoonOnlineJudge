#include <bits/stdc++.h>
#define INF 987654321

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
        int m = INF;
        int M = -INF;
        int N;
        cin >> N;
        vector<int> v(N);
        for (auto& i : v) cin >> i;
        for (auto i : v)
        {
            m = min(m, i);
            M = max(M, i);
            
        }
        cout << m << ' ' << M << '\n';
    }
}