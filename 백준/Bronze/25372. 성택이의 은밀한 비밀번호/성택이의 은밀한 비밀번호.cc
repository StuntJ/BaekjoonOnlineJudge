#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;
        if(str.size()>=6 && str.size()<=9) cout<<"yes\n";
        else cout<<"no\n";
    }
}