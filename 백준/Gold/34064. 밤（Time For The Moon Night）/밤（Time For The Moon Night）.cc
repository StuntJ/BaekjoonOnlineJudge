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

    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<bool>> grid(N+1,vector<bool>(M+1));
    while(K--){
        int x,y;
        cin>>x>>y;

        grid[x][y] = true;
    }
    vector<vector<int>> num(N+1,vector<int>(M+1));
    vector<vector<bool>> visited = grid;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    auto dfs = [&](auto &dfs, int x, int y, int color)->void{
        visited[x][y] = true;
        num[x][y] = color;

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<nx&&nx<=N && 0<ny&&ny<=M){
                if(!visited[nx][ny]){
                    dfs(dfs,nx,ny,color);
                }
            }
        }
    };

    int idx = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!visited[i][j]) dfs(dfs,i,j,idx++);
            if(grid[i][j]) num[i][j] = -1;
        }
    }

    vector<ll> cnts(idx), cnte(idx);
    int ssx,ssy,sex,sey;
    int esx,esy,eex,eey;
    cin>>ssx>>ssy>>sex>>sey>>esx>>esy>>eex>>eey;

    for(int i=ssx;i<=sex;i++){
        for(int j=ssy;j<=sey;j++){
            if(num[i][j]!=-1)
                cnts[num[i][j]]++;
        }
    }

    
    for(int i=esx;i<=eex;i++){
        for(int j=esy;j<=eey;j++){
            if(num[i][j]!=-1)
                cnte[num[i][j]]++;
        }
    }

    ll sum = 0;
    for(int i=0;i<idx;i++)
        sum += cnts[i]*cnte[i];
    cout<<sum;
}