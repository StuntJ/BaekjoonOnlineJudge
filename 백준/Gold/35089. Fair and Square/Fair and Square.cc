#include <bits/stdc++.h>

using namespace std;

void solve(){
    int h,w;
    cin>>h>>w;

    vector<vector<char>> grid(h,vector<char>(w));
    for(auto &i : grid) for(auto &j : i) cin>>j;

    int cnt = 0;
    for(auto i : grid) for(auto j : i) if(j=='#') cnt++;

    vector<int> cand;
    for(int i=1;i<=min(h,w);i++){
        if(!(cnt%(i*i))) cand.emplace_back(i); 
    }

    sort(cand.begin(),cand.end(),greater<int>());

    int ans = 0;
    for(auto k : cand){
        bool flag = true;
        vector<vector<bool>> visited(h,vector<bool>(w));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                
                if(grid[i][j]=='#'&&!visited[i][j]){
                    if(!(i+k-1<h && j+k-1<w)){
                        flag = false;
                        break;
                    } 
                    for(int l=i;l<i+k;l++){
                        for(int m=j;m<j+k;m++){
                            if(grid[l][m]!='#'||visited[l][m]){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag) break;
                    }
                    if(flag){
                        for(int l=i;l<i+k;l++){
                            for(int m=j;m<j+k;m++){
                                visited[l][m] = true;   
                            }
                        }   
                    }              
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(flag){
            ans = k;
            break;
        }
    }
    cout<<ans;

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    } 
}