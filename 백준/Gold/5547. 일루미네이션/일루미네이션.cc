#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx1[6] = {-1,-1,0,0,1,1};
    int dy1[6] = {-1,0,-1,1,-1,0};
    int dx0[6] = {-1,-1,0,0,1,1};
    int dy0[6] = {0,1,-1,1,0,1};

    int W,H;
    cin>>W>>H;

    vector<vector<int>> grid(H,vector<int>(W));
    vector<vector<bool>> visited(H,vector<bool>(W));
    for(auto &i : grid)
        for(auto &j : i)
            cin>>j;

    queue<pair<int,int>> q;
    auto dfs = [&](auto &dfs, int x, int y)->bool{
        q.push({x,y});
        visited[x][y] = true;
        int ret = true;
        for(int i=0;i<6;i++){
            int nx, ny;
            if(x&1){
                nx = x+dx1[i];
                ny = y+dy1[i];
            }
            else{
                nx = x+dx0[i];
                ny = y+dy0[i];
            }
            if(0<=nx&&nx<H && 0<=ny&&ny<W){
                if(grid[nx][ny]==0&&!visited[nx][ny])
                    ret &= dfs(dfs,nx,ny);
            }
            else{
                ret = false;
            }
        }
        return ret;
    };

    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(!visited[h][w] && grid[h][w]==0){
                if(dfs(dfs,h,w)){
                    while(!q.empty()){
                        grid[q.front().first][q.front().second] = 1;
                        q.pop();
                    }
                }
                while(!q.empty()) q.pop();
            }
                
        }
    }

    /* cout<<'\n';
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++)
            cout<<grid[h][w]<<' ';
        cout<<'\n';
    } */
            
    int ans = 0;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(grid[h][w]){
                int cnt = 6;
                if(h&1){
                    for(int i=0;i<6;i++){
                        int nx = h + dx1[i];
                        int ny = w + dy1[i];
                        if(0<=nx && nx<H && 0<=ny && ny<W){
                            if(grid[nx][ny]) cnt--;
                        }
                    }
                }
                else{
                    for(int i=0;i<6;i++){
                        int nx = h + dx0[i];
                        int ny = w + dy0[i];
                        if(0<=nx && nx<H && 0<=ny && ny<W){
                            if(grid[nx][ny]) cnt--;
                        }
                    }
                }
                ans += cnt;
            }
            
        }
    }
    cout<<ans;
}