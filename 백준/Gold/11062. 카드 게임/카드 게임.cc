#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N;
        vector<int> v(N);
        for(auto &i : v) cin>>i;

        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));

        auto solve = [&](auto &solve, int x, int y)->int{
            if(x+y>=N) return 0;
            int &ret = dp[x][y];
            if(ret!=-1) return ret;
            ret = 0;
            
            int r1 = min(solve(solve,x+2,y),solve(solve,x+1,y+1)) +v[x];
            int r2 = min(solve(solve,x+1,y+1),solve(solve,x,y+2)) +v[N-y-1];

            ret = max(r1,r2);
            return ret;
        };

        
        cout<<solve(solve,0,0)<<'\n';
        /* for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                cout<<dp[i][j]<< ' ';
            }
            cout<<'\n';
        } */
    }
}