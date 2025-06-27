#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,a,b;
    cin>>N>>a>>b;

    if(a+b-1>N){
        cout<<-1<<'\n';
        return 0;
    }

    vector<int> h;
    int idx = 0;
    for(int i=0;i<a;i++){
        h.push_back(++idx);
    }
    if(b>h.back()) h.back() = b;
    idx = b;
    for(int i=0;i<b-1;i++){
        h.push_back(--idx);
    }

    for(int i=0;i<N-(a+b-1);i++)
        h.insert(h.begin()+1,1);
    
    for(auto &i : h) cout<<i<<' ';
}