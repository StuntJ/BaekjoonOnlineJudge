#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<bool> v(6);
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v[x] = true;
    }
    for(int i=1;i<6;i++){
        if(!v[i]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}