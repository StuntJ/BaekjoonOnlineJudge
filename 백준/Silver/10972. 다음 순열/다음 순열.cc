#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;

    bool t = next_permutation(v.begin(),v.end());

    if(t){
        for(auto i : v) cout<<i<<' ';
    }
    else cout<<-1<<'\n';
}