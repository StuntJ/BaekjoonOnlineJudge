#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    set<pair<int,int>> st;
    map<pair<int,int>,bool> visited;
    int N;
    cin>>N;
    int idx = 0;
    int prev = -1;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;

        if(prev>=x) idx++;
        st.insert({idx,x});
        visited.insert(make_pair(make_pair(idx,x),false));
        prev = x;
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    auto dfs = [&](auto &dfs, int x, int y)->void{
        visited[{x,y}] = true;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(visited.find({nx,ny}) !=visited.end() && !visited[{nx,ny}]){
                dfs(dfs,nx,ny);
            }
        }
    };

    int cnt = 0;
    for(auto here : st){
        if(!visited[here]){
            cnt++;
            dfs(dfs,here.first,here.second);
        }
    }
    cout<<cnt<< '\n'<<N;
}