#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> b(3,vector<int>(3));
    int f =0, s = 0;
    for(auto &i : b){
        for(auto &j : i)
        { 
            cin>>j;
            if(j==1) f++;
            else if(j==2) s++;
        }
    }

    bool turn = false;
    if(f>s) turn = true;

    auto solve = [&](auto &solve, int depth, vector<vector<int>> &v)->int{
        bool end = true;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!v[i][j]){
                    end = false;
                    break;
                }
            }
        }
        if(end) return 0;

        int fill = (turn^(depth&1)) + 1; //0 이면 1번 1이면 2번
        int ret = ((depth&1) ? 30 : -30);
        int w = ((depth&1) ? -1 : 1);

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(v[i][j]==0){
                    v[i][j] = fill;
                    bool e = false;
                    if(v[i][0]==v[i][1] && v[i][1]==v[i][2]&&v[i][0]!=0){
                        if(depth&1) ret = min(ret,w);
                        else ret = max(ret, w);
                        e = true;
                    }
                    if(v[0][j]==v[1][j] && v[1][j]==v[2][j]&&v[0][j]!=0){
                        if(depth&1) ret = min(ret,w);
                        else ret = max(ret, w);
                        e = true;
                    }
                    if(v[0][0]==v[1][1] && v[1][1]==v[2][2]&&v[0][0]!=0){
                        if(depth&1) ret = min(ret,w);
                        else ret = max(ret, w);
                        e = true;
                    }
                    if(v[0][2]==v[1][1] && v[1][1]==v[2][0]&&v[0][2]!=0){
                        if(depth&1) ret = min(ret,w);
                        else ret = max(ret, w);
                        e = true;
                    }

                    if(!e) 
                    {
                        if(depth&1)
                            ret = min(ret,solve(solve,depth+1,v));
                        else ret = max(ret,solve(solve,depth+1,v));
                    }

                    v[i][j] = 0;
                }
            }
        }

        /* for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<v[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<ret<<'\n';
        cout<<'\n'; */

        return ret;
    };
    int ans = solve(solve,0,b);
    if(ans==1) cout<<"W";
    else if(ans==0) cout<<"D";
    else cout<<"L";
}