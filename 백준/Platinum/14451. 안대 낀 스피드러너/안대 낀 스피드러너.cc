#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[4][21][21][4][21][21];

struct q_data{
    int aDir;
    int ax;
    int ay;
    int bDir;
    int bx;
    int by;
};

void solve(){
    int N;
    cin>>N;

    vector<vector<char>> grid(N,vector<char>(N));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>grid[i][j];

    reverse(grid.begin(),grid.end());

    //(0,0) - (N-1,N-1) 이동

    queue<q_data> q;
    q.push({0,0,0,1,0,0});
    
    memset(visited,-1,sizeof(visited));
    visited[0][0][0][1][0][0] = 0;

    auto isInrange = [&](int x, int y)->bool{
        if(0<=x&&x<N && 0<=y&&y<N && grid[x][y]!='H') return true;
        return false;
    };

    while(!q.empty()){
        q_data here = q.front();
        q.pop();

        if(here.ax == N-1 && here.ay == N-1 && here.bx == N-1 && here.by == N-1){
            continue;   
        }

        //Turn Right
        q_data nextR = here;
        nextR.aDir = (nextR.aDir+1)%4;
        nextR.bDir = (nextR.bDir+1)%4;
        if(visited[nextR.aDir][nextR.ax][nextR.ay][nextR.bDir][nextR.bx][nextR.by]==-1){
            visited[nextR.aDir][nextR.ax][nextR.ay][nextR.bDir][nextR.bx][nextR.by] = visited[here.aDir][here.ax][here.ay][here.bDir][here.bx][here.by] + 1;

            q.push(nextR);
        }

        //Turn Left
        q_data nextL = here;
        nextL.aDir = (nextL.aDir-1+4)%4;
        nextL.bDir = (nextL.bDir-1+4)%4;
        if(visited[nextL.aDir][nextL.ax][nextL.ay][nextL.bDir][nextL.bx][nextL.by]==-1){
            visited[nextL.aDir][nextL.ax][nextL.ay][nextL.bDir][nextL.bx][nextL.by] = visited[here.aDir][here.ax][here.ay][here.bDir][here.bx][here.by] + 1;

            q.push(nextL);
        }

        //Forward
        q_data nextF = here;
        bool aFlag = false;
        if(!(nextF.ax==N-1 && nextF.ay==N-1)){
            int nx = nextF.ax+dx[nextF.aDir];
            int ny = nextF.ay+dy[nextF.aDir];
            if(isInrange(nx,ny)){
                nextF.ax = nx;
                nextF.ay = ny;
                aFlag = true;
            }
        }

        bool bFlag = false;
        if(!(nextF.bx==N-1 && nextF.by==N-1)){
            int nx = nextF.bx+dx[nextF.bDir];
            int ny = nextF.by+dy[nextF.bDir];
            if(isInrange(nx,ny)){
                nextF.bx = nx;
                nextF.by = ny;
                bFlag = true;
            }
        }

        if(aFlag || bFlag){
            if(visited[nextF.aDir][nextF.ax][nextF.ay][nextF.bDir][nextF.bx][nextF.by]==-1)
            {
                visited[nextF.aDir][nextF.ax][nextF.ay][nextF.bDir][nextF.bx][nextF.by] = visited[here.aDir][here.ax][here.ay][here.bDir][here.bx][here.by] + 1;
                q.push(nextF);
            }
        }
    }

    int ans = 1000;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(visited[i][N-1][N-1][j][N-1][N-1]==-1) continue;
            ans = min(ans,visited[i][N-1][N-1][j][N-1][N-1]);
        }
    }

    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}