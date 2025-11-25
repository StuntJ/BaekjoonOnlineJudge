#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int idx = 0;
    while(idx+1<s.size()){
        string sub1 = s.substr(idx,2);
        if(sub1=="pi"||sub1=="ka"){
            idx+=2;
            continue;
        }
        if(idx+2<s.size()){
            string sub2 = s.substr(idx,3);
            if(sub2=="chu"){
                idx+=3;
                continue;
            }   
        }
        cout<<"NO";
        return 0;
    }
    if(idx==s.size()) cout<<"YES";
    else cout<<"NO";
}