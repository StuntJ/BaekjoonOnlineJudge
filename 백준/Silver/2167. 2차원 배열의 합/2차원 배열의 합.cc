#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> v(N+1,vector<int>(M+1));
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>v[i][j];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            v[i][j] = v[i][j] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }

    int q;
    cin>>q;
    while(q--){
        int i,j,x,y;
        cin>>i>>j>>x>>y;

        cout<<v[x][y]-v[x][j-1]-v[i-1][y]+v[i-1][j-1]<<'\n';
    }
}