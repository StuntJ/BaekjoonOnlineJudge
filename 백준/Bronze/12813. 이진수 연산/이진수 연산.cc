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
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    string AND, OR, XOR, NA, NB;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '1' && B[i] == '1')
        {
            AND.push_back('1');
            OR.push_back('1');
            XOR.push_back('0');
            NA.push_back('0');
            NB.push_back('0');
        }
        else if (A[i] == '0' && B[i] == '1')
        {
            AND.push_back('0');
            OR.push_back('1');
            XOR.push_back('1');
            NA.push_back('1');
            NB.push_back('0');
        }
        else if (A[i] == '1' && B[i] == '0')
        {
            AND.push_back('0');
            OR.push_back('1');
            XOR.push_back('1');
            NA.push_back('0');
            NB.push_back('1');
        }
        else if (A[i] == '0' && B[i] == '0')
        {
            AND.push_back('0');
            OR.push_back('0');
            XOR.push_back('0');
            NA.push_back('1');
            NB.push_back('1');
        }
    }

    cout << AND << '\n';
    cout << OR << '\n';
    cout << XOR << '\n';
    cout << NA << '\n';
    cout << NB << '\n';
}