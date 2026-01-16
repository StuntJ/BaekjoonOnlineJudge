#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<char> v(N);
    for(auto &i : v) cin>>i;

    int cnt = 0;
    char c;
    cin>>c;
    for(auto i : v){
        if(c==i) cnt++;
    }
    cout<<cnt;
}