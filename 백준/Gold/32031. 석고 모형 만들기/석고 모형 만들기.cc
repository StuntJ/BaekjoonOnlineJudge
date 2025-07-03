#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R,C;
    cin>>R>>C;
    vector<vector<vector<int>>> grid(3,vector<vector<int>>(R*3,vector<int>(C*3,1)));

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char p;
            cin>>p;
            for(int x = i*3;x<i*3+3;x++){
                for(int y=j*3;y<j*3+3;y++){
                    for(int z=0;z<3;z++){
                        if(p=='O'){
                            if((x==i*3&&y==j*3+1)||(x==i*3+1)||(x==i*3+2&&y==j*3+1)){
                                grid[z][x][y] = 0;
                            }
                        }
                        else if(p=='H'){
                            if((z==0&&x==i*3+1)||z==1||(z==2&&x==i*3+1)){
                                grid[z][x][y] = 0;
                            }
                        }
                        else{
                            if((z==0&&y==j*3+1)||z==1||(z==2&&y==j*3+1)){
                                grid[z][x][y] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    vector<vector<vector<bool>>> visited(3,vector<vector<bool>>(R*3,vector<bool>(C*3)));
    int dx[6] = {0,0,0,0,1,-1};
    int dy[6] = {0,0,1,-1,0,0};
    int dz[6] = {1,-1,0,0,0,0};

    auto dfs = [&](auto &dfs, int x, int y, int z)->void{
        visited[x][y][z] = true;
        for(int i=0;i<6;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];
            if(0<=nx&&nx<3 && 0<=ny&&ny<R*3 && 0<=nz&&nz<C*3){
                if(!visited[nx][ny][nz] && grid[nx][ny][nz]==1){
                    dfs(dfs,nx,ny,nz);
                }
            }
        }
    };

    int cnt = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<R*3;j++){
            for(int k=0;k<C*3;k++){
                if(!visited[i][j][k]&&grid[i][j][k]==1){
                    dfs(dfs,i,j,k);
                    cnt++;
                }
            }
        }
    }

    cout<<cnt<<'\n';
    /* for(int i=0;i<3;i++){
        for(int j=0;j<R*3;j++){
            for(int k=0;k<C*3;k++){
                cout<<grid[i][j][k]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
    } */
}