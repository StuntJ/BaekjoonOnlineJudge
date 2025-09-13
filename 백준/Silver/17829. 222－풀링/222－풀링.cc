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

int fpow(int n, int p){
    if(p==0) return 1;
    int temp = fpow(n,p/2);
    int ret = temp*temp;
    if(p&1) return ret*n;
    else return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vvi v(N,vi(N));
    for(auto &i : v) for(auto &j : i) cin>>j;

    while(N/2!=0){
        vvi bp(N/2,vi(N/2));
        int x = 0, y = 0;
        for(int i=0;i<N;i+=2){
            for(int j=0;j<N;j+=2){
                vi g;
                for(int k=i;k<=i+1;k++){
                    for(int l=j;l<=j+1;l++){
                        g.push_back(v[k][l]);
                    }
                }
                sort(g.begin(),g.end());
                bp[x][y++] = g[2];
            }
            y = 0;
            x++;
        }
        v = bp;
        N/=2;
        /* for(auto i : v){
            for(auto j : i)
                cout<<j<<' ';
            cout<<'\n';
        }
        cout<<'\n'; */
    }
    cout<<v[0][0];
}