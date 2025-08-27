#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);

    vector<vector<int>> adj(N+1);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<vector<int>> dp(N+1,vector<int>(2,-1));

    auto dfs = [&](auto &dfs, int parent, int here, bool can)->int{
        int &ret = dp[here][can];
        if(ret!=-1) return ret;
        ret = 0;
        bool flag = false;
        int sum1 = 0, sum2 = 0;
        for(auto next : adj[here]){
            if(next==parent) continue;
            flag = true;
            sum1 += dfs(dfs,here,next,0);
            sum2 += dfs(dfs,here,next,1);
        }

        if(can) ret = max(sum1+v[here],sum2);
        else ret = sum2;

        if(!flag){
            if(can) return ret = v[here];
            else return ret = 0;
        }

        return ret;
    };

    cout<<dfs(dfs,-1,1,1)<<'\n';

    vector<int> ans;
    auto backtrack = [&](auto &backtrack,int parent, int here, bool can)->void{
        if(can==0){
            for(auto next : adj[here]){
                if(parent==next) continue;
                backtrack(backtrack,here,next,1);
            }
        }
        else{
            int sum1 = 0, sum2 = 0;
            for(auto next : adj[here]){
                if(parent==next) continue;
                sum1 += dp[next][0];
                sum2 += dp[next][1];
            }

            if(dp[here][can]-sum1 == v[here]){
                ans.emplace_back(here);
                for(auto next : adj[here]){
                    if(next==parent) continue;
                    backtrack(backtrack,here,next,0);
                }
            }
            else{
                for(auto next : adj[here]){
                    if(next==parent) continue;
                    backtrack(backtrack,here,next,1);
                }
            }
        }
    };
    backtrack(backtrack,-1,1,1);
    sort(ans.begin(),ans.end());
    for(auto i : ans) cout<<i<<' ';
}