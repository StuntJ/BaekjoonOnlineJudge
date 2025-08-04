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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vvc grid(N+1,vc(M+1));
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>grid[i][j];

    vvi g1(N+1,vi(M+1)), g2(N+1,vi(M+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(((i+j)&1)){
                if(grid[i][j]=='W') g1[i][j] = 1;
                else g2[i][j] = 1;
            }
            else{
                if(grid[i][j]=='W') g2[i][j] = 1;
                else g1[i][j] = 1;
            } 
        }
    }

    ll cnt = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int temp = min(g1[i-1][j-1],min(g1[i][j-1],g1[i-1][j]));
            if(g1[i][j])
                g1[i][j] = max(g1[i][j],temp+1);
            
            cnt += g1[i][j];
            temp = min(g2[i-1][j-1],min(g2[i-1][j],g2[i][j-1]));
            if(g2[i][j])
                g2[i][j] = max(g2[i][j],temp+1);
            cnt += g2[i][j];
        }
    }
    /* for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<g1[i][j]<<' ';
        }
        cout<<'\n';
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<g2[i][j]<<' ';
        }
        cout<<'\n';
    } */
    cout<<cnt;
}