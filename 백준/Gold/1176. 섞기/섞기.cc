#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin>>N>>K;

    vector<int> height(N);
    for(auto &i : height) cin>>i;
    height.insert(height.begin(),0);

    vector<vector<int>> adj(N+1);
    for(int i=0;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(i==0){
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
            else{
                if(abs(height[i]-height[j])>K){
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
    }

    vector<vector<ll>> dp((1<<(N+1)),vector<ll>(N+1,-1));

    auto solve = [&](auto &solve, int stat, int here)->ll{
        if(stat==(1<<(N+1))-1) return 1;
        ll &ret = dp[stat][here];
        if(ret!=-1) return ret;
        ret = 0;

        for(auto next : adj[here]){
            if(stat&(1<<(next))) continue;
            ret += solve(solve, stat|(1<<next),next);
        }
        return ret;
    };

    cout<<solve(solve, 1, 0);
}