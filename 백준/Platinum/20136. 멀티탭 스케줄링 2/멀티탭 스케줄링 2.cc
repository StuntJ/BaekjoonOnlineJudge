#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;

void solve(){
    int N,K;
    cin>>N>>K;

    vector<vector<int>> pos(K+1);
    vector<int> idx(K+1);
    vector<int> v(K);
    for(int i=0;i<K;i++){
        cin>>v[i];
        pos[v[i]].emplace_back(i);
    }
    for(int i=1;i<=K;i++){
        pos[i].emplace_back(INF);
    }

    set<pair<int,int>> pq;
    unordered_set<int> st;

    int cnt = 0;
    for(int i=0;i<K;i++){
        if(st.find(v[i])!=st.end()){
            pq.erase(pq.begin());
            if(++idx[v[i]]<pos[v[i]].size()){
                pq.insert({pos[v[i]][idx[v[i]]],v[i]});
            }
            continue;
        }
        if(st.size()<N){
            if(++idx[v[i]]<pos[v[i]].size()){
                pq.insert({pos[v[i]][idx[v[i]]],v[i]});
            }
            st.insert(v[i]);
        }
        else{
            cnt++;
            if(!pq.empty()){
                int t = prev(pq.end())->first;
                int x = prev(pq.end())->second;
                pq.erase(prev(pq.end()));   

                st.erase(x);
            }
            else{
                st.erase(st.begin());
            }
            if(++idx[v[i]]<pos[v[i]].size()){
                pq.insert({pos[v[i]][idx[v[i]]],v[i]});
            }
            st.insert(v[i]);
        }
    }
    cout<<cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}