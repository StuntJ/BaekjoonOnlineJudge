#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
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

const ll mod = 1e9+7;

ll Pow(ll n, ll p)
{
    if(p==1) return n;
    ll temp = Pow(n,p/2);
    ll ret = temp*temp;
    if(p&1) return ret*n;
    return ret;
}

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

    int N,M;
    cin>>N>>M;

    if(N<M){
        cout<<1;
        return 0;
    }

    vvll m0(M,vll(1,1));
    vvll p(M,vll(M));
    p[0][0] = p[0][M-1] = 1;
    for(int i=1;i<M;i++){
        p[i][i-1] = 1;
    }

    p = matrixPower(p,N-M+1,mod);
    vvll ans = matrixProduct(p,m0,mod);
    cout<<ans[0][0];
}