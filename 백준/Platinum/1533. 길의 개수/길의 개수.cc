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

const ll DIV = 1000003;

vvll matrixProduct(vvll& A, vvll& B, ll mod)
{
    int Ais = (int)A.size();
    int Bjs = (int)B[0].size();
    int Bis = (int)B.size();

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

    int N,S,E,T;
    cin>>N>>S>>E>>T;
    S--;
    E--;
    
    vvc inp(N,vc(N));
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>inp[i][j];
    
    vvll mt(N*5,vll(N*5));
    
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<5;j++)
        {
            mt[i*5+j][i*5+j-1] = 1;
        }
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int dist = inp[i][j]-'0';
            if(dist!=0) mt[i*5][j*5+dist-1] = 1;
        }
    }
    
    /*for(int i=0;i<N*5;i++)
    {
        for(int j=0;j<N*5;j++)
            cout<<mt[i][j]<<' ';
        cout<<'\n';
    }*/
    
    vvll ans = matrixPower(mt, T, DIV);
    
    cout<<ans[S*5][E*5]<<'\n';
}
