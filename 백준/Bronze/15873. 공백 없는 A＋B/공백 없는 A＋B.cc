#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;

    int t1,t2;

    int idx = 0;

    if(str[0]=='1'&&str[1]=='0'){
        t1 = stoi(str.substr(0,2));
        idx = 2;
    }
    else{
        t1 = stoi(str.substr(0,1));
        idx = 1;
    } 

    t2 = stoi(str.substr(idx));

    cout<<t1+t2;
}