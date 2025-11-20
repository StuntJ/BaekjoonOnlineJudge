#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;

    if(N&1){
        cout<<"Bob";
    }
    else{
        bool flag = true;
        int k = v[0];
        for(int i=1;i<N;i++){
            if(v[i]!=k){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"Bob";
        else cout<<"Alice";
    } 
}