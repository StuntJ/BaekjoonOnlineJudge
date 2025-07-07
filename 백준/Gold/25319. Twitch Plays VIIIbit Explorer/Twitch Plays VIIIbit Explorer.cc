#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,S;
    cin>>N>>M>>S;

    vector<vector<char>> grid(N,vector<char>(M));
    vector<vector<bool>> visited(N,vector<bool>(M));
    for(auto &i : grid)
        for(auto &j : i)
            cin>>j;

    string str;
    cin>>str;
    map<char,int> cnt;
    for(auto i : str) cnt[i]++;
    map<char,pair<int,vector<pair<int,int>>>> mp;
    for(auto ch : str){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==ch && !visited[i][j]){
                    visited[i][j] = true;
                    mp[ch].second.push_back({i,j});
                }
            }
        }
    }
    int msize = 1e9;
    for(auto ch : str) msize = min((int)mp[ch].second.size()/cnt[ch],msize);

    string ans;
    pair<int,int> prev = {0,0};

    auto putstr = [&](pair<int,int> a, pair<int,int> b){
        int updown = b.first-a.first;
        if(updown>0) ans.append(updown,'D');
        else ans.append(-updown,'U');
        int leftright = b.second-a.second;
        if(leftright>0) ans.append(leftright,'R');
        else ans.append(-leftright,'L');
    };

    for(int i=0;i<msize;i++){
        for(auto ch : str){
            putstr(prev,mp[ch].second[mp[ch].first]);
            ans.push_back('P');
            prev = mp[ch].second[mp[ch].first++];
        }
    }

    putstr(prev,{N-1,M-1});

    cout<<msize<<' '<<ans.size()<<'\n';
    cout<<ans<<'\n';
}