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

    int x,y;
    cin>>x>>y;
    
    int a0,a1;
    cin>>a0>>a1;

    int N;
    cin>>N;
    if(N==0){
        if(a0<10) cout<<0;
        cout<<a0;
        return 0;
    }
    if(N==1){
        if(a1<10) cout<<0;
        cout<<a1;
        return 0;
    }

    vvll f(2,vll(1));
    f[0][0] = a1;
    f[1][0] = a0;

    vvll p(2,vll(2));
    p[0][0] = x;
    p[0][1] = y;
    p[1][0] = 1;
    p[1][1] = 0;

    p = matrixPower(p,N-1,100);

    vvll ans = matrixProduct(p,f,100);

    if(ans[0][0]<10) cout<<0;
    cout<<ans[0][0];

}