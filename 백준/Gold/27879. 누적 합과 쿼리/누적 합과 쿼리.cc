#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<vector<char>> grid(N+1,vector<char>(N+1));
    for(int i=1;i<=N;i++){
        int idx = 1;
        while(idx<=N){
            char x;
            cin>>x;
            if(x!=' ')
                grid[i][idx++] = x;
        }    
    }
    
    vector<vector<vector<int>>> pSum(4,vector<vector<int>>(N+1,vector<int>(N+1)));
    vector<vector<vector<int>>> lr,ud;
    lr = ud = pSum;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i!=1){
                string str;
                str.push_back(grid[i-1][j]);
                str.push_back(grid[i][j]);

                int idx = 0;
                if(str=="aa") idx = 0;
                else if(str=="ab") idx = 1;
                else if(str=="ba") idx = 2;
                else idx = 3;

                ud[idx][i][j]++;
                pSum[idx][i][j]++;
            }
            if(j!=1){
                string str;
                str.push_back(grid[i][j-1]);
                str.push_back(grid[i][j]);

                int idx = 0;
                if(str=="aa") idx = 0;
                else if(str=="ab") idx = 1;
                else if(str=="ba") idx = 2;
                else idx = 3;

                lr[idx][i][j]++;
                pSum[idx][i][j]++;
            }       
        }
    }

    for(int i=0;i<4;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                pSum[i][j][k] += pSum[i][j-1][k] + pSum[i][j][k-1] - pSum[i][j-1][k-1];
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                lr[i][j][k] += lr[i][j-1][k];
                ud[i][j][k] += ud[i][j][k-1];
            }
        }
    }

    int Q;
    cin>>Q;
    while(Q--){
        int a,b,c,d;
        string str;
        cin>>a>>b>>c>>d>>str;
        int idx = 0;
        if(str=="aa") idx = 0;
        else if(str=="ab") idx = 1;
        else if(str=="ba") idx = 2;
        else idx = 3;

        cout<<pSum[idx][c][d] + pSum[idx][a-1][b-1] - pSum[idx][a-1][d] - pSum[idx][c][b-1] - (ud[idx][a][d]-ud[idx][a][b-1]) - (lr[idx][c][b]-lr[idx][a-1][b])<<'\n';
    } 
}