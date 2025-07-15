#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[6] = {-2,-2,0,0,2,2};
    int dy[6] = {-1,1,-2,2,-1,1};

    int N;
    cin>>N;
    vector<vector<int>> dist(N,vector<int>(N,-1));
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    queue<pair<int,int>> q;
    dist[r1][c1] = 0;
    q.push({r1,c1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==r2 && y==c2){
            break;
        }

        for(int i=0;i<6;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx&&nx<N && 0<=ny&&ny<N){
                if(dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout<<dist[r2][c2];
}