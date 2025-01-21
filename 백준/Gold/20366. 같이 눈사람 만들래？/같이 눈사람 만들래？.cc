#include <bits/stdc++.h>
#define INF 1000000000000000

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (auto& i : H) cin >> i;

    sort(H.begin(), H.end());
    ll ans = INF;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                ll p = H[i] + H[k] - H[j];
                ll q = H[j] + H[k] - H[i];

                auto iter = lower_bound(H.begin() + k + 1, H.end(), p);
                ll cand;
                if(iter!=H.end())
                {
                    cand = *iter;
                    ans = min(ans, abs(p - cand));
                }
                iter = prev(iter);
                if (iter != H.begin() + k)
                {
                    cand = *iter;
                    ans = min(ans, abs(p - cand));
                }
                iter = lower_bound(H.begin() + k + 1, H.end(), q);
                if(iter!=H.end())
                {
                    cand = *iter;
                    ans = min(ans, abs(q - cand));
                }
                iter = prev(iter);
                if (iter != H.begin() + k)
                {
                    cand = *iter;
                    ans = min(ans, abs(q - cand));
                }
            }
        }
    }
    cout << ans << '\n';
}