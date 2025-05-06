#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v(N);
    for (auto& i : v)
    {
        int a;
        cin >> a;
        cin >> i.first >> i.second;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        int a = v[i].first;
        int b = v[i].second;

        if (pq.empty())
            pq.push(b);
        else
        {
            if (a >= pq.top())
            {
                pq.pop();
                pq.push(b);
            }
            else
            {
                pq.push(b);
            }
        }

    }
    cout << pq.size();
}
