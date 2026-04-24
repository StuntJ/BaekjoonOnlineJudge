#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N,M;
    cin>>N>>M;
    
    vector<string> v(N*2);
    for(auto &i : v) cin>>i;
    
    vector<vector<vector<int>>> table(N,vector<vector<int>>(N,vector<int>(M)));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int idx = 0;
            while(idx<M){
                int st = idx;
                int cnt = 0;
                if(v[i][idx]!=v[j+N][idx]){
                    idx++;
                    continue;
                }
                while(idx<M&&v[i][idx]==v[j+N][idx]){
                    idx++;
                    cnt++;
                }
            
                while(st<idx){
                    if(idx==M){
                        table[i][j][st] = 1e9;
                        st++;
                    }
                    else{
                        table[i][j][st] = cnt--;
                        st++;
                    }
                }    
            }
        }
    }
    
    int mnSee = 1e9;;
    for(int k=0;k<M;k++){
        int mxSee = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) mxSee = max(table[i][j][k]+1,mxSee);
        }
        mnSee = min(mnSee,mxSee);
    }
    
    cout<<mnSee;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; //cin>>t;
    while(t--) solve();
}