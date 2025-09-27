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

    vvll grid(N+1,vll(M+1));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>grid[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i>=2 && j>=2) grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            else if(i>=2) grid[i][j] += grid[i-1][j];
            else if(j>=2) grid[i][j] += grid[i][j-1];
        }
    }

    ll t;
    cin>>t;
    if(grid[N][M]>t) cout<<"NO";
    else{
        cout<<"YES\n";
        cout<<grid[N][M];
    }
}