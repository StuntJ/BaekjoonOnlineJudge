#include <bits/stdc++.h>
#define MAX 10001

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vi v(MAX);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < v[i]; j++)
            cout << i << '\n';
    }
    
}