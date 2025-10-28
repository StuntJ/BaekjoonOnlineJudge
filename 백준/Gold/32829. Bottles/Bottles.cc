#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n,vector<int>(m));
    for(auto &i : v) for(auto &j : i) cin>>j;
    vector<int> dist(n);

    for(int i=0;i<m;i++){
        int mx = 0;
        vector<pair<int,int>> seq;
        for(int j=0;j<n;j++){
            seq.push_back({dist[j],1});
            seq.push_back({dist[j]+v[j][i],-1});
            dist[j] += v[j][i];
        }
        sort(seq.begin(),seq.end());
        int cnt = 0;
        for(int j=0;j<seq.size();j++){
            cnt += seq[j].second;
            if(seq[j+1].first-seq[j].first>0) mx = max(cnt,mx);
        }
        cout<<mx<<' ';
    }
}