#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (auto& i : v) cin >> i;

    int i = 0;
    int sum = 0;
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
        sum += v[j];
        while (i <= j && sum > M)
        {
            sum -= v[i++];
        }
        if (sum == M) cnt++;
    }
    cout << cnt << '\n';
}