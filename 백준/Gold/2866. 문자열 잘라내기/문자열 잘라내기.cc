#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R,C;
    cin>>R>>C;
    vector<vector<char>> grid(R,vector<char>(C));
    for(auto &i : grid)
        for(auto &j : i) 
            cin>>j;

    vector<string> vstr;
    for(int j=0;j<C;j++){
        string str;
        for(int i=0;i<R;i++) str.push_back(grid[i][j]);
        vstr.push_back(str);
    }

    int cnt = 0;
    
    for(int i=1;i<R;i++){
        unordered_set<string> st;
        bool flag = true;
        for(int j=0;j<C;j++){
            string str = vstr[j].substr(i);
            if(st.find(str)==st.end())
                st.insert(str);
            else{
                flag = false;
                break;
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout<<cnt;
}