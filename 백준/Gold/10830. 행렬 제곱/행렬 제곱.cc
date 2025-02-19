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

vvll matrixProduct(vvll& A, vvll& B, ll mod)
{
    int Ais = A.size();
    int Bjs = B[0].size();
    int Bis = B.size();

    vvll C = vvll(Ais, vll(Bjs));
    for (int i = 0; i < Ais; i++)
    {
        for (int j = 0; j < Bjs; j++)
        {
            for (int k = 0; k < Bis; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

vvll matrixPower(vvll& A, ll p, ll mod)
{
    if (p == 1) return A;
    vvll temp = matrixPower(A, p / 2, mod);
    vvll ret = matrixProduct(temp, temp, mod);
    if (p & 1) return matrixProduct(A, ret,mod);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, B;
    cin >> N >> B;
    vvll v(N, vll(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
            v[i][j] %= 1000;
        }
    }

    vvll res = matrixPower(v, B, 1000);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << res[i][j] << ' ';
        cout << '\n';
    }
}