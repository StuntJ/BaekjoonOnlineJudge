#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<int> v(N);
    for(auto &i : v) cin>>i;

    v.insert(v.begin(),0);
    
    for(int i=1;i<=N;i++) v[i] += v[i-1];

    for(int i=N;i>=1;i--){
        int sum = v[N]-v[i-1];
        if(sum>=M){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}