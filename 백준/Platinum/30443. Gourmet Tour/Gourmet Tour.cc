#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<vector<int>> adj(N+1);
    vector<int> inDegree(N+1);
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        inDegree[a]++;
        inDegree[b]++;
    }

    vector<int> depth(N+1,-1);

    auto getDepth = [&](auto &getDepth, int here, int parent = -1, int d)->void{
        if(adj[here].size()==1) depth[here] = d;
        for(auto &next : adj[here]){
            if(next==parent) continue;
            getDepth(getDepth,next,here,d+1);
        }
    };

    getDepth(getDepth,1,-1,1);

    //for(auto &i : depth) cout<<i<<' ';

    int st = max_element(depth.begin()+1,depth.end())-depth.begin();

    vector<int> ans(N+1);
    ans[st] = 1;
    int num = 1;
    auto dfs = [&](auto &dfs, int d, int here, int parent = -1)->void{
        int k = ((d&1) ? -1 : 1);
        int nxtnode = 0;
        for(auto next : adj[here]){
            if(next==parent) continue;
            if(inDegree[next]!=1){
                nxtnode = next;
                continue;
            }
            ans[next] = ans[here] + k * (num++);
        }
        if(nxtnode){
            ans[nxtnode] = ans[here] + k*(num++);
            dfs(dfs,d+1,nxtnode,here);
        }
        return;
    };
    dfs(dfs,0,st);
    int small = *min_element(ans.begin()+1,ans.end());
    int add = 1-small;
    for(int i=1;i<=N;i++)
        cout<<ans[i]+add<<' ';
}