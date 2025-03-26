#include <bits/stdc++.h>
#define MAX 14

using namespace std;
typedef long long ll;

int N, M;

ll cache[MAX * MAX][1 << MAX];

ll solve(int idx, int stat)
{
    if (idx >= N * M)
    {
        if (idx == N * M && stat == 0)
            return 1;
        return 0;
    }

    ll& ret = cache[idx][stat];
    if (ret != -1) return ret;
    ret = 0;

    if (stat & (1 << 0)) ret += solve(idx + 1, stat >> 1);
    else
    {
        if (idx % M != M - 1 && (stat & (1 << 1)) == 0)
            ret += solve(idx + 2, stat >> 2);
        ret += solve(idx + 1, (stat >> 1) | (1 << (M - 1)));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0) return 0;
        memset(cache, -1, sizeof(cache));
        cout << solve(0, 0) << '\n';
    }
}
