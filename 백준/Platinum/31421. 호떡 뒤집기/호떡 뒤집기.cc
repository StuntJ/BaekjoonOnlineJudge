#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    string str;
    cin>>str;

    vector<int> v;
    for(int i=0;i<N-1;i++){
        if(str[i]!=str[i+1]){
            v.emplace_back(i+1);
        }
    }
    if((v.size()==1 && str[0]=='W')||(v.size()==0 && str[0]=='B')){
        cout<<-1;
        return 0;
    }

    int sz = v.size();
    if(sz==0){
        cout<<0;
        return 0;
    }
    if((v.size()&1) && str[0]=='W'){
        swap(v[sz-1],v[sz-2]);
    }
    if(!(v.size()&1) && str[0]=='B'){
        swap(v[sz-1],v[sz-2]);
    }
    cout<<v.size()<<'\n';
    for(auto &i : v) cout<<i<<'\n';
}