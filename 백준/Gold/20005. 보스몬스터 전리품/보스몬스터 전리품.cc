#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,P;
    cin>>N>>M>>P;
    vector<vector<char>> grid(N,vector<char>(M));
    array<int,3> boloc;
    for(auto &i : grid)
        for(auto &j : i)
            cin>>j;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j]=='B')
                boloc = {i,j,0};
        }
    }

    
    map<char,int> mp;
    while(P--){
        char p;
        int k;
        cin>>p>>k;

        mp.insert({p,k});
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int bohp;
    cin>>bohp;

    vector<vector<int>> boss(N,vector<int>(M));
    queue<array<int,3>> q;
    vector<vector<bool>> visited(N,vector<bool>(M));
    q.push({boloc});
    visited[boloc[0]][boloc[1]] = true;
    boss[boloc[0]][boloc[1]] = bohp;

    int updtime = -1;
    int attack = 0;
    int updattack = 0;
    int cnt = 0;
    while(!q.empty()){
        auto [x,y,t] = q.front();
        q.pop();

        if(t==updtime){
            attack+=updattack;
            updtime = -1;
            updattack = 0;
        }

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny= y+dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(!visited[nx][ny]&&grid[nx][ny]!='X'){
                    boss[nx][ny] = boss[x][y] - attack;
                    if(grid[nx][ny]>='a'&& grid[nx][ny]<='z'){
                        updtime = t+1;
                        updattack += mp[grid[nx][ny]];
                        if(boss[nx][ny]>0) cnt++; 
                    }
                    q.push({nx,ny,t+1});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    cout<<cnt;
}