#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M,K;
    cin>>N>>M>>K;
    vector<pair<int,int>> v(K);
    for(auto &i : v) cin>>i.first>>i.second;

    bool arr1[2][2] = {0,};
    bool arr2[2][2] = {0,};

    for(auto &i : v){
        int x = i.first;
        int y = i.second;

        arr1[x&1][y&1] = true;
        arr2[(x+1)&1][(y+1)&1] = true;
    }

    bool flag1 = true;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(!arr1[i][j]){
                flag1 = false;
                break;
            }
        }
        
    }
    bool flag2 = true;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(!arr2[i][j]){
                flag2 = false;
                break;
            }
        }
        
    }
    if(flag1||flag2){
        cout<<"YES";
    }
    else cout<<"NO";
}