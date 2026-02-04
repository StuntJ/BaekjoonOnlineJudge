#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    
    vector<int> v(n);
    for(auto &i : v) cin>>i;
    v.emplace_back(v[0]);

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(v[i]>=v[i+1]){
            cnt++;
        }
    }
    cout<<cnt;
}