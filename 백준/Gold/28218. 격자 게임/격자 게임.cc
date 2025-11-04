#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<char>> grid(N+1,vector<char>(M+1));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>grid[i][j];
    
    vector<vector<vector<int>>> cache(2,vector<vector<int>>(N+1,vector<int>(M+1,-1)));

    auto isInrange = [&](int x, int y){
        if(!(1<=x&&x<=N && 1<=y&&y<=M)) return false;
        if(grid[x][y]=='#') return false;
        return true;
    };

    auto solve = [&](auto &solve, int t, int x, int y)->bool{
        if(x==N&&y==M) return !t;
        int &ret = cache[t][x][y];
        if(ret!=-1) return ret;

        ret = !t;

        if(isInrange(x+1,y)&&solve(solve,!t,x+1,y)==t) ret = t;
        if(isInrange(x,y+1)&&solve(solve,!t,x,y+1)==t) ret = t;
        for(int i=1;i<=K;i++){
            if(isInrange(x+i,y+i)&&solve(solve,!t,x+i,y+i)==t) ret = t;
        }  
        return ret;
    };

    int Q;
    cin>>Q;
    while(Q--){
        int x, y;
        cin>>x>>y;
        bool ans = solve(solve,0,x,y);
        if(ans) cout<<"Second"<<'\n';
        else cout<<"First"<<'\n';
    }
}