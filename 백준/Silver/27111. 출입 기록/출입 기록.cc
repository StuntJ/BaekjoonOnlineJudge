#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    map<int,bool> mp;

    int error = 0;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;

        if(mp.find(a)==mp.end()){
            if(b==0) error++;
            else mp[a] = b;
        }
        else{
            if(mp[a]==b) error++;
            mp[a] = b;
        }
    }

    for(auto i : mp) if(i.second) error++;
    cout<<error;
}