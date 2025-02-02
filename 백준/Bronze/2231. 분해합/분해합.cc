#include <bits/stdc++.h>

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

    int N;
    cin >> N;

    //int generator = 0;
    for (int i = 1; i < N; i++)
    {
        string str = to_string(i);
        int sum = i;
        for (auto i : str) sum += i - '0';
        {
            if (sum == N) 
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    cout << 0;
}