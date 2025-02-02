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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int next;
    for (int i = 3; i >= 1; i--)
    {
        string str;
        cin >> str;
        if ('0' <= str[0] && str[0] <= '9')
            next = stoi(str) + i;

    }
    if (next % 3 == 0 && next % 5 == 0) cout << "FizzBuzz" << '\n';
    else if (next % 3 == 0) cout << "Fizz" << '\n';
    else if (next % 5 == 0) cout << "Buzz" << '\n';
    else cout << next << '\n';
}