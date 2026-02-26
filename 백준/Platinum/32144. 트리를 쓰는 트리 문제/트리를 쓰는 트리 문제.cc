#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N;
    cin>>N;

    vector<vector<int>> tree(N+1);
    vector<int> par(N+1,-1);
    for(int i=2;i<=N;i++){
        int p;
        cin>>p;

        par[i] = p;
        tree[i].emplace_back(p);
        tree[p].emplace_back(i);
    }

    vector<int> Deep1(N+1), Deep2(N+1), Diameter(N+1), Deep1Ver(N+1);
    vector<unordered_map<int,int>> dirDeep(N+1);
    
    function<void(int,int)> dfs1 = [&](int here, int parent = -1){
        int diameter = 0;
        int depth1 = 0;
        int depth2 = 0;

        for(auto next : tree[here]){
            if(next==parent) continue;
            dfs1(next,here);
        }

        for(auto next : tree[here]){
            if(next==parent) continue;
            //dirDeep[here][next] = Deep1[next] + 1;
            if(depth1 < Deep1[next]+1){
                if(depth2<depth1) depth2 = depth1;
                depth1 = Deep1[next]+1;
                Deep1Ver[here] = next;
            }
            else if(depth2 < Deep1[next]+1) depth2 = Deep1[next] + 1;
            diameter = max(diameter,Diameter[next]);
        }
        diameter = max(diameter,depth1+depth2); 
        
        Deep1[here] = depth1;
        Deep2[here] = depth2;
        Diameter[here] = diameter;
    };
    
    dfs1(1,-1);
    int minDiameter = Diameter[1];

    function<void(int,int)> dfs2 = [&](int here, int parent=-1){
        if(parent!=-1){
            int upDepth = 0;
            if(Deep1Ver[parent]==here){
                upDepth = Deep2[parent]+1;
            }
            else upDepth = Deep1[parent]+1;

            if(Deep1[here] < upDepth){
                if(Deep2[here]<Deep1[here]) Deep2[here] = Deep1[here];
                Deep1Ver[here] = parent;
                Deep1[here] = upDepth;
            }
            else if(Deep2[here] < upDepth) Deep2[here] = upDepth;
        } 

        for(auto next : tree[here]){
            if(next==parent) continue;
            dfs2(next,here);
        }
    };
    dfs2(1,-1);

    vector<int> res(N+1,minDiameter);
    for(int vertex=2;vertex<=N;vertex++){
        int mxDist = 0;
        if(Deep1Ver[par[vertex]]==vertex){
            mxDist = Deep2[par[vertex]];
        }
        else mxDist = Deep1[par[vertex]];
        res[vertex] = max(res[vertex],mxDist+Diameter[vertex]+1);
        cout<<res[vertex]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}