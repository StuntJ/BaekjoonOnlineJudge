#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> grid(N+1,vector<int>(M+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            cin>>grid[i][j];
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int t = max(grid[i-1][j-1],max(grid[i][j-1],grid[i-1][j]));
            grid[i][j] += t;
        }
    }
    cout<<grid[N][M];
}