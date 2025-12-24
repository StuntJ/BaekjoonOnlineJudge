#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    int R;
    cin>>R;

    vector<vector<pair<int,int>>> adj(N+1);

    for(int i=0;i<N-1;i++){
        int a,b,d;
        cin>>a>>b>>d;

        adj[a].emplace_back(make_pair(b,d));
        adj[b].emplace_back(make_pair(a,d));
    }

    int giga;
    int gigaParent;

    auto findGiga = [&](auto &findGiga, int here, int parent = -1)->int{
        gigaParent = parent;
        giga = here;
        if((here==R && adj[here].size()>=2) || adj[here].size()>=3){    
            return 0;
        } 
        int ret = 0;
        for(auto next : adj[here]){
            if(next.first==parent) continue;
            ret += findGiga(findGiga,next.first,here) + next.second;
        }
        return ret;
    };

    int mxR = findGiga(findGiga,R);

    auto findMxBranch = [&](auto &findMxBranch,int here, int parent = -1)->int{
        int ret = 0;
        for(auto next : adj[here]){
            if(next.first==parent) continue;
            ret = max(ret, findMxBranch(findMxBranch,next.first,here) + next.second);
        }
        return ret;
    };

    int mx = findMxBranch(findMxBranch,giga,gigaParent);
    cout<<mxR<<' '<<mx;
}