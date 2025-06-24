#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> bit(N);
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int x;
            cin>>x;
            x--;

            bit[i] += (1<<x);
        }
    }

    /* for(auto i : bit){
        bitset<9> k(i);
        cout<<k<<'\n';
    } */

    for(int i=1;i<N;i++){
        int able = 0;
        for(int j=0;j<9;j++){
            int p = (1<<j);
            int bp = p^bit[i-1];
            if(bp!=p && bp!=0) able += p;
        }
        bit[i] = able&bit[i];
    }
    /* for(auto i : bit){
        bitset<9> k(i);
        cout<<k<<'\n';
    } */

    vector<int> ans;
    if(bit[N-1]==0) cout<<-1;
    else{
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<9;j++){
                int p = (1<<j);
                int con = (i==N-1 ? 0 : (1<<(ans.back()-1)));
                if((p&bit[i])&&((p&con)==0)){
                    ans.push_back(j+1);
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        for(auto &i : ans)
            cout<<i<<'\n';
    }
}