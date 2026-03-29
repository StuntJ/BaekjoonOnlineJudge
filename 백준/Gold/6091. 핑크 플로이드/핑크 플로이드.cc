#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;

    vector<vector<int>> dist(N+1,vector<int>(N+1));

    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            int x;
            cin>>x;
            dist[i][j] = x;
            dist[j][i] = x;
        }
    }

    vector<vector<int>> tree(N+1);

    for(int i=2;i<=N;i++){
        int cand = -1;
        int minDist = 1e9;
        for(int j=1;j<=N;j++){
            if(i==j) continue;
            if(dist[i][j]+dist[j][1]==dist[i][1]){
                if(dist[i][j]<minDist){
                    cand = j;
                    minDist = dist[i][j];
                } 
            } 
        }
        if(cand==-1){
            cout<<"No";
            return;
        }

        tree[i].push_back(cand);
        tree[cand].push_back(i);
    }

    function<bool(int,int,int,int)> dfs = [&](int here, int parent, int length, int pivot){
        if(dist[pivot][here]!=length) return false;
        bool ret = true;

        for(auto next : tree[here]){
            if(next==parent) continue;
            ret &= dfs(next,here,length+dist[here][next],pivot);
        }

        return ret;
    };

    bool ans = true;
    for(int i=1;i<=N;i++){
        ans &= dfs(i,-1,0,i);
    }

    if(ans){
        for(int i=1;i<=N;i++) sort(tree[i].begin(),tree[i].end());
        for(int i=1;i<=N;i++){
            cout<<tree[i].size()<<' ';
            for(auto j : tree[i]) cout<<j<<' ';
            cout<<'\n';
        }
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