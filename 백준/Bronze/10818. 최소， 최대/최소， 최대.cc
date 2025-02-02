#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (auto& i : v) cin >> i;
    cout << *min_element(v.begin(), v.end()) << ' ';
    cout << *max_element(v.begin(), v.end()) << '\n';
}