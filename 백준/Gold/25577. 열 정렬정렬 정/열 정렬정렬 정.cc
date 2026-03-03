#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N;
    cin>>N;

    unordered_map<int,int> mp;
    vector<int> v(N),cpv;
    for(auto &i : v) cin>>i;

    cpv = v;
    sort(cpv.begin(),cpv.end());

    for(int i=0;i<N;i++){
        mp[cpv[i]] = i;
    }

    vector<int> res(N);
    for(int i=0;i<N;i++){
        res[i] = mp[v[i]];
    }

    vector<int> visited(N);

    function<void(int)> dfs = [&](int here){
        visited[here] = true;
        if(!visited[res[here]])
            dfs(res[here]);
    };

    int cnt = 0;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<N-cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}