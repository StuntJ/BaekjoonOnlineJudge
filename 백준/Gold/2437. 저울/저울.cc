#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;

    sort(v.begin(),v.end());

    if(v[0]!=1){
        cout<<1;
        return;
    }

    int sum = v[0];
    for(int i=1;i<N;i++){
        if(v[i]>sum+1){
            cout<<sum+1;
            return;
        }
        sum += v[i];
    }

    cout<<sum+1;
    return;
        
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}