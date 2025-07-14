#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;
    vector<vector<ll>> grid(N,vector<ll>(M));
    bool flag = false;
    for(auto &i : grid){
        for(auto &j : i){
            cin>>j;
            if(j==0){
                flag = true;
            }
        }
    }
    if(flag){
        ll sum = 0;
        for(auto i : grid)
            sum += accumulate(i.begin(),i.end(),0LL);
        cout<<sum<<'\n';
        return 0;
    }
    if(N==1 && M==1){
        cout<<grid[0][0]<<'\n';
        return 0;
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    pair<int,int> c1,c2;
    ll mval = 1e15;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(0<=nx&&nx<N && 0<=ny&&ny<M){
                    ll t = min(grid[i][j],grid[nx][ny]);
                    if(t<mval){
                        mval = t;
                        c1 = {i,j};
                        c2 = {nx,ny};
                    }
                }
            }
        }
    }
    ll minus = min(grid[c1.first][c1.second],grid[c2.first][c2.second]);
    grid[c1.first][c1.second]-=minus;
    grid[c2.first][c2.second]-=minus;

    ll sum = minus;
    for(auto i : grid)
        sum += accumulate(i.begin(),i.end(),0LL);
    cout<<sum<<'\n';
    //cout<<minus<<'\n';
    //cout<<c1.first<<' '<<c1.second<<' '<<c2.first<<' '<<c2.second<<'\n';
}