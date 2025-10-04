#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<vector<int>> grid(N,vector<int>(N));

    for(auto &i : grid) for(auto &j : i) cin>>j;

    int st = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==2){
                st += i+j;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==1){
                if((i+j)%2==st%2){
                    cout<<"Kiriya";
                    return 0;
                }
            }
        }
    }
    cout<<"Lena";
}