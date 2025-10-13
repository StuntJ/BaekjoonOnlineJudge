#include <bits/stdc++.h>
#define MAX_N 101

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin>>Q;

    vector<vector<int>> adj(MAX_N);
    vector<pair<int,int>> v;

    int idx = 0;
    auto dfs = [&](auto &dfs, int here, const int dest, vector<bool> &visited)->bool{
        if(here==dest) return true;
        visited[here] = true;
        bool ret = false;
        for(auto next : adj[here]){
            if(!visited[next])
                ret |= dfs(dfs,next,dest,visited);
        }
        return ret;
    };

    while(Q--){
        int q;
        int x,y;
        cin>>q>>x>>y;
        if(q==1){ //x,y 구간 추가 
            v.push_back({x,y});
            idx++;
            for(int i=0;i<idx-1;i++){ //add -> origin
                if(x<v[i].first&&v[i].first<y || x<v[i].second&&v[i].second<y){
                    adj[i].emplace_back(idx-1);
                }
                if(v[i].first<x&&x<v[i].second || v[i].first<y&&y<v[i].second){
                    adj[idx-1].emplace_back(i);
                }
            }
        }
        else{ //x->y 경로 확인
            x--; y--;
            vector<bool> visited(idx);

            cout<<dfs(dfs,x,y,visited)<<'\n';
        }
    }

    /* for(auto i : adj){
        for(auto j : i){
            cout<<j<<' ';
        }
        cout<<'\n';
    } */
}