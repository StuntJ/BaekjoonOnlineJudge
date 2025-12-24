#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<char>> grid(N,vector<char>(M));
    for(auto &i : grid) for(auto &j : i) cin>>j;

    pair<int,int> sang,sun;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j]=='A') sang = {i,j};
            if(grid[i][j]=='B') sun = {i,j};
        }
    }

    vector<vector<int>> distSang(N,vector<int>(M,-1));
    vector<vector<int>> distSun(N,vector<int>(M,-1));

    int dx1[4] = {0,1,-1,0};
    int dy1[4] = {1,0,0,-1};

    distSang[sang.first][sang.second] = 0;
    queue<pair<int,int>> q2;
    q2.push(sang);
    while(!q2.empty()){
        pair<int,int> here = q2.front();
        q2.pop();

        for(int i=0;i<4;i++){
            int nx = here.first + dx1[i];
            int ny = here.second + dy1[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && (grid[nx][ny]!='G') && (distSang[nx][ny]==-1)){
                distSang[nx][ny] = distSang[here.first][here.second] + 1;
                q2.push({nx,ny});
            }
        }
    }

    int mn = 1e9;
    int num = 2*(N+M)-4;
    int x = sun.first, y = sun.second;
    int prev = -1;
    while(distSun[x][y]==-1){
        distSun[x][y] = prev+1;
        prev = distSun[x][y];

        int u = distSun[x][y];
        int v = distSang[x][y];

        while(u<v){
            u+=num;
        }
        
        if(v!=-1 && (u-v)%2==0){
            mn = min(v + (u-v)/2,mn);
        }

        if(x==0 && y<M-1) y++;
        else if(y==M-1 && x<N-1) x++;
        else if(x==N-1 && y>0) y--;
        else if(y==0 && x>0) x--;        
    }

    /* for(auto &i : distSun){
        for(auto &j : i){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';

    for(auto &i : distSang){
        for(auto &j : i){
            cout<<j<<' ';
        }
        cout<<'\n';
    } */
    if(mn==1e9) cout<<"-1";
    else cout<<mn;
}