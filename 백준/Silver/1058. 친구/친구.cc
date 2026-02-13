#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<vector<char>> v(N,vector<char>(N));
    for(auto &i : v) for(auto &j : i) cin>>j;

    int mx = 0;
    for(int i=0;i<N;i++){
        int cnt = 0;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(v[i][j]=='Y') cnt++;
            else{
                for(int k=0;k<N;k++){
                    if(v[i][k]==v[k][j]&&v[k][j]=='Y'){
                        if(i!=k&&k!=j){
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        mx= max(cnt,mx);
    }
    cout<<mx;
}